/* baghchal.c - webpage and char-based shell implementations combined
 *            - Andy Ganse, 12/15/99, andy@ganse.org
 *
 * usage1: (char-based shell version) :
 *         baghchal
 *
 * usage2: (called from webpage form via POST method) :
 *         baghchal player=<TorG>&skill=<skill>&round=<round>&...
 *            boardarray=<boardarray>&goatstaken=<goatstaken>&move=<moveentry>
 *
 * Board layout is the following, with array position reference #'s as well as
 * letter/number positions as used in the game:
 *
 *                           A     B     C     D     E
 *
 *                       1   0  -- 1  -- 2  -- 3  -- 4
 *                           | \   |   / | \   |   / |
 *                           |   \ | /   |   \ | /   |
 *                       2   5  -- 6  -- 7  -- 8  -- 9
 *                           |   / | \   |   / | \   |
 *                           | /   |   \ | /   |   \ |
 *                       3   10 -- 11 -- 12 -- 13 -- 14
 *                           | \   |   / | \   |   / |
 *                           |   \ | /   |   \ | /   |
 *                       4   15 -- 16 -- 17 -- 18 -- 19
 *                           |   / | \   |   / | \   |
 *                           | /   |   \ | /   |   \ |
 *                       5   20 -- 21 -- 22 -- 23 -- 24
 */

#define displayTextError printf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "baghchal.h"


int main( int argc, char *argv[] ) {
 
   /* vars */
   char humanplayer;
   int skill, goatstaken=0, round=0, winFlag=0;
   int boardarray[25]={1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1};
   int move[2]={-1,-1};  /* from boardarray element A to element B */
   int complastmove[2]={-1,-1};  /* from boardarray element A to element B */
   char moveString[6];
   int validmove=0;

   /* function prototypes */
   int initGameMovementRules();
   int playOneTurn( char *humanplayer, int *skill, int *round, int *boardarray,
      int *move, int *complastmove, int *goatstaken, int *winFlag );
   int moveStr2Array( char *moveString, int *move, int moveStringLen );
   int invalidMoveEntry( char *moveString );
   /* int displayTextError( char *errormsg ); */
   int displayTextBoard(char humanplayer, int skill, int round,
      int boardarray[25], int complastmove[2], int goatstaken);
   
 
   /* define game movement rules (set up some structs to do this) */
   initGameMovementRules();


   /* Write out game-intro info */
   printf("\n");
   printf("Welcome to BAGH CHAL, the Nepali game of tigers and goats.\n");
   printf("---------------------------------------------------------------\n");
   printf("\n");
   printf("Please see the accompanying text file baghchal.readme for rules\n");
   printf("of the game and background information.\n\n");
   printf("After each round of the game, a new board will be displayed\n");
   printf("with both your move and the computer's response move.  Other\n");
   printf("info will also be displayed with each new board, like round #,\n");
   printf("how many goats have been taken, and so on.  To enter your move,\n");
   printf("note the ABCDE & 12345 row & column markers on the gameboard,\n");
   printf("and enter your move (when prompted) per these examples:\n");
   printf("  Enter your move:  a2,b3     [tiger, or goat after 20th round]\n");
   printf("  Enter your move:  c3        [goat before 20th round]\n\n");
   printf("If you want to quit the game early, just enter q or quit\n");
   printf("instead at any of the prompts.\n\n");


   /* Ask player for skill level and whether they want to be tiger or goat */
   printf("What skill level would you like to play at?  Enter 1, 2, or 3 :  ");
   scanf("%1d", &skill);
   if( skill!=1 && skill!=2 && skill!=3 ) exit( FAILED );
   printf("\n");
   printf("Would you like to be the tiger player or goat player?\n");
   printf("(Either way, the goat player goes first.)  Enter t or g :  ");
   scanf("\n%c", &humanplayer);
   if( humanplayer!='t' && humanplayer!='g' &&
       humanplayer!='T' && humanplayer!='G' ) exit( FAILED );
   humanplayer=toupper(humanplayer);


   /* Actually play the game - loop over rounds */
   while( !winFlag ) {

      /* Turn includes both human move and computer move */
      if(playOneTurn( &humanplayer, &skill, &round, boardarray, move, 
         complastmove, &goatstaken, &winFlag ) == INVALID_MOVE ) {
         displayTextError("              "
                          "Invalid game move for %s. Try again.\n",
                          (humanplayer=='T')?"Tiger":"Goat" );
      }
      else {  /* (if turn was valid) */
         /* Display the resulting gameboard */
         displayTextBoard( humanplayer, skill, round, boardarray, complastmove,
            goatstaken );
      }

      if( !winFlag ) {
         /* request move */
         validmove=0;
         while( !validmove ) {
            printf("                                     Enter your move :  ");
            scanf("\n%5s", moveString);

            /* validate move entry, and set "move" array out of that */
            if( !strcmp(moveString,"q") || !strcmp(moveString,"quit") ||
                !strcmp(moveString,"Q") || !strcmp(moveString,"QUIT") ||
                !strcmp(moveString,"Quit") || !strcmp(moveString,"exit") ||
                !strcmp(moveString,"Exit") || !strcmp(moveString,"EXIT")  )
               exit( SUCCESSFUL );
            if( invalidMoveEntry(moveString) ) {
               displayTextError("                       "
                                "Invalid move entry. Try again.\n");
            }
            else {
               moveStr2Array(moveString, move, strlen(moveString) );
               validmove=1;
            }
         }
      }
      else
         printf("                                     %s won!",
            (winFlag=='T')?"Tiger":"Goat" );

      printf("\n");

   }

   exit( SUCCESSFUL );

}



int invalidMoveEntry( char *moveString ) {

   if( ( strlen(moveString)==2 &&
         moveString[0]>='a' && moveString[0]<='e' &&
         moveString[1]>='1' && moveString[1]<='5' 
       ) ||
       ( strlen(moveString)==5 &&
         moveString[0]>='a' && moveString[0]<='e' &&
         moveString[1]>='1' && moveString[1]<='5' &&
         moveString[2]==',' &&
         moveString[3]>='a' && moveString[3]<='e' &&
         moveString[4]>='1' && moveString[4]<='5'
       )
     ) return SUCCESSFUL;  /* (valid) */

   else return FAILED;  /* (invalid) */

}

