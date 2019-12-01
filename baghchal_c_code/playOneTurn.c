#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "baghchal.h"

int playOneTurn( char *humanplayer, int *skill, int *round, int *boardarray,
   int *move, int *complastmove, int *goatstaken, int *winFlag ) {

   /*
   printf("playone inp:  h=%c, s=%d, r=%d, m=%d-%d, c=%d-%d, g=%d, w=%d\n",
      *humanplayer, *skill, *round, move[0], move[1], complastmove[0], complastmove[1], *goatstaken, *winFlag);
   printf("             b=");
   for(int i=0;i<25;i++) printf("%d",boardarray[i]);
   printf("\n");
   */

  /* function prototypes */
   int validate_player_move(char *humanplayer, int move[2], int *round,
      int *boardarray);
   int place_move_in_boardarray(char *player, int *round, int *move,
      int *boardarray, int *goatstaken);
   int determine_comp_move(char *compplayer, int *boardarray, int *skill,
      int *move, int *round);
   int check_for_win(char *player, int *boardarray, int *goatstaken);

   /* set compplayer to opposite of humanplayer - just a way to keep them
   straight, it got too confusing otherwise... */
   char compplayer[1]; /*(still not sure why I couldnt use "char *compplayer")*/
   *compplayer = (*humanplayer=='T')?'G':'T';
 

   /* goat always goes 1st, so do nothing on initial round if hplayer is goat*/
   if( !(*round==0 && *humanplayer=='G') ) {   
 
      /* play the human player */
      if( !(*round==0) ) {   /* compplayer goes first if it's the goat */
         /* check if hplayer's possibly-valid move works on present gameboard*/
         if(validate_player_move(humanplayer, move, round, boardarray)==FAILED){
            return(INVALID_MOVE);
         }
  
         /* assign human player's move in gameboard array (& record goat jump
            if applicable) */
         place_move_in_boardarray(humanplayer, round, move, boardarray, goatstaken);

         /* see if human player won */
         if( check_for_win(humanplayer, boardarray, goatstaken)==WINNER ) {
            *winFlag=*humanplayer;
            return GAME_OVER;
         }
      }
  
      /* play the computer player */
      {
         /* figure out the computer player's move */
         determine_comp_move(compplayer, boardarray, skill, move, round);
     
         /* assign comp player's move in gameboard array (& record goat jump
            if applicable) */
         place_move_in_boardarray(compplayer, round, move, boardarray,
            goatstaken);
     
         /* see if comp player won */
         if( check_for_win(compplayer, boardarray, goatstaken)==WINNER ) {
            *winFlag=*compplayer;
            return GAME_OVER;
         }
      }

   }
   else {
      /* If got here, means human player is G on first round, and there was
      no earlier computer player move to refer to - hence the null move here */
      move[0]=-1; move[1]=-1;
   }
 
   complastmove[0]=move[0];   /* since final use of 'move' was for compplayer */
   complastmove[1]=move[1];
   (*round)++;

   /*
   printf("playone out:  h=%c, s=%d, r=%d, m=%d-%d, c=%d-%d, g=%d, w=%d\n",
      *humanplayer, *skill, *round, move[0], move[1], complastmove[0], complastmove[1], *goatstaken, *winFlag);
   printf("             b=");
   for(int i=0;i<25;i++) printf("%d",boardarray[i]);
   printf("\n");
   */

   return SUCCESSFUL;

}






int validate_player_move(char *player, int move[2], int *round, int boardarray[25]) {
   /*
   printf("validate:  pl=%c, m=%d-%d, r=%d, b=", *player, move[0], move[1], *round);
   for(int i=0;i<25;i++) printf("%d",boardarray[i]);
   printf("\n");
   */

   int i, ok=0;

   if( *player=='G' && *round<21 ) {
      if( boardarray[ move[0] ] == 0 /*(blank)*/ ) ok=1;
   }
   else if( *player=='G' && *round>=21 ) {
      if( boardarray[move[0]]==2 /*(goat)*/ && boardarray[move[1]]==0 ) {
         for( i=0; i<GameBoardPos[move[0]].NumCanMoveTo; i++ )
            if( move[1]==GameBoardPos[move[0]].CanMoveTo[i].Pos ) ok=1;
      }
   }
   else if( *player=='T' ) {
      if( boardarray[move[0]]==1 /*(tiger)*/ && boardarray[move[1]]==0 ) {
         /*
         printf("move=%d-%d\n", move[0], move[1]);
         printf("numcanmoveto %d\n", GameBoardPos[0].NumCanMoveTo);
         printf("numcanmoveto %d\n", GameBoardPos[move[0]].NumCanMoveTo);
         */
         for( i=0; i<GameBoardPos[move[0]].NumCanMoveTo; i++ )
            /* why do these printf() lines interfere with stored values & cause trouble?
            printf("i %d\n", i);
            printf("canmoveto %d\n", GameBoardPos[move[0]].CanMoveTo[i].Pos);
            printf("canjumpto %d\n", GameBoardPos[move[0]].CanMoveTo[i].CanJumpToPos);
            printf("nogoat %d\n", boardarray[ GameBoardPos[move[0]].CanMoveTo[i].Pos ]==2 );
            */
            if( move[1]==GameBoardPos[move[0]].CanMoveTo[i].Pos ||
                (move[1]==GameBoardPos[move[0]].CanMoveTo[i].CanJumpToPos &&
                 boardarray[ GameBoardPos[move[0]].CanMoveTo[i].Pos ]==2 )   ) {
               ok=1;
            }
      }
   }

   if(ok) return SUCCESSFUL;
   else return FAILED;
 
}





int place_move_in_boardarray(char *player, int *round, int move[2], 
   int boardarray[25], int *goatstaken) {

   int i;

   if (*player=='G' && *round < 21) {
      /* just add new goat to the blank (already validated) spot on the board */
      boardarray[ move[0] ] = 2;
   }
   else {
   /* player is a mover - either a tiger, or a goat after all goats on board */
      /* add piece to new spot, remove piece from old spot */
      boardarray[ move[1] ] = (*player=='T')?1:2 ;
      boardarray[ move[0] ] = 0;

      /* if player is a tiger, check for whether a goat was jumped by comparing
         move to GameBoardPos movement-rules array; if goat was jumped, tally
         it and remove it from boardarray. */
      if( *player=='T' ) {
         for( i=0; i<GameBoardPos[move[0]].NumCanMoveTo; i++ ) {
            if( move[1]==GameBoardPos[move[0]].CanMoveTo[i].CanJumpToPos ) {
               if( boardarray[ GameBoardPos[move[0]].CanMoveTo[i].Pos ]==2 ) {
                  (*goatstaken)++;
                  boardarray[ GameBoardPos[move[0]].CanMoveTo[i].Pos ]=0;
               }
            }
         }
      }


   }
   return SUCCESSFUL;
}





int determine_comp_move(char *player, int boardarray[], int *skill,
   int move[2], int *round ) {

   int randint(int max);
   int i, j, b=1, m, n, blankspot[10], blankcnt, spotcnt, jumpFlag=0;
  
   if(*player=='T') {   /* if computer player is tiger */

      /* check if one of the tigers has a jumping opportunity and use it */
      for( i=0; i<25; i++ ) {
         if( boardarray[i]==1 /*(tiger)*/ ) {
            for( j=0; j<GameBoardPos[i].NumCanMoveTo; j++ ) {
               if( boardarray[GameBoardPos[i].CanMoveTo[j].CanJumpToPos]==0
                   && boardarray[GameBoardPos[i].CanMoveTo[j].Pos]==2 ) {
                   move[0]=i;
                   move[1]=GameBoardPos[i].CanMoveTo[j].CanJumpToPos;
                   jumpFlag=1;
               }
            }
         }
      }

      if(!jumpFlag) {   /* if was no jumping opportunity, just move randomly */
         n=randint(4)-1; /* randomly choose which of 4 tigers (0-3) to move */
   
         /* find array position of nth tiger */
         for( i=0; i<25; i++ ) {
            if( boardarray[i]==1 /*(tiger)*/ ) {
               if( n!=0 ) n--;
               else break; /* desired tiger now at array pos i, so cut loop */
            }
         }
         /* i at this point is the position of desired tiger */
   
         /* count num possible moves from that position, pick one, and move */
         for( j=0; j<10; j++ ) blankspot[j]=0; /*(zero out array to use again)*/
         m=0;
         for( j=0; j<GameBoardPos[i].NumCanMoveTo; j++ )
            if( boardarray[GameBoardPos[i].CanMoveTo[j].Pos]==0 ) 
               blankspot[m++]=j;
         n=randint(m)-1;  /* choose randomly from indices of blank spots */
         move[0]=i;
         move[1]=GameBoardPos[i].CanMoveTo[blankspot[n]].Pos;
      }
   }

   else {  /* if computer player is goat */
      if (*round<21) {   /* round<=20 : placing a goat in an open space */
         for(blankcnt=0, i=0; i<25; i++)
            if(boardarray[i]==0) blankcnt++; /*count blank spots left on board*/

         n=randint(blankcnt);  /* choose randomly from those blank spots */

         /* find n-th blank spot =b in boardarray */
         for(spotcnt=0, i=0; i<25 && spotcnt<n; i++)
            if(boardarray[i]==0) {
               spotcnt++; 
               b=i;
            }

         /* convert b to move[] */
         move[0]=b;
         move[1]=-1;
      }
      else {  /* round>=21 : all goats on board, so choose a goat to move */
      ;
      }

   }

   return SUCCESSFUL;
}




int check_for_win(char *player, int boardarray[], int *goatstaken) {
   if( *player=='T' && *goatstaken==MAX_GOATS_TAKEN ) return WINNER;
   else return SUCCESSFUL;
}




/* returns random integer between 1 and specified max (inclusive) */
int randint(int max) {
   srand(time(NULL) % 32767);     /* time-based random seed between 0 & 32767 */
   return 1+(int) max*(rand()/(RAND_MAX+1.0));        /* RAND_MAX in stdlib.h */
}

