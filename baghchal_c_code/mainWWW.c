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
#include "baghChal.h"


int main( int argc, char *argv[] ) {
 
   /* vars */
   char humanplayer;
   int skill, goatstaken=0, round=0, winFlag=0;
   int boardarray[25]={1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1};
   int move[2]={-1,-1};  /* from boardarray element A to element B */
   int complastmove[2]={-1,-1};  /* from boardarray element A to element B */
   char inputline[100]="", errormsg[80];
   int status;

   /* function prototypes */
   int initGameMovementRules();
   int playOneTurn( char *humanplayer, int *skill, int *round, int *boardarray,
      int *move, int *complastmove, int *goatstaken, int *winFlag );
   int moveStr2Array( char *moveString, int *move, int moveStringLen );
   int invalidMoveEntry( char *moveString );
   /* int displayTextError( char *errormsg ); */
   int validateParams( char *inputline, char *humanplayer, int *skill,
      int *round, int boardarray[25], int *goatstaken, int move[2] );
   int displayWWWError( char *errormsg );
   int outputHTMLpage(char player, int skill, int round, int boardarray[25],
      int complastmove[2], int goatstaken, int winFlag);
   
 
   /* define game movement rules (set up some structs to do this) */
   initGameMovementRules();


   /* assign first 91 (at most) chars of stdin to inputline
      (a security approach to prevent overloaded input) */
   if( fscanf( stdin, "%91s", inputline ) < 1 ) {
      sprintf( errormsg, "error in assigning stdin to inputline[]\n" );
      displayWWWError( errormsg );
      exit( FAILED );
   }
 
   /* load and check params from cmdline */
   if( validateParams( inputline, &humanplayer, &skill, &round, boardarray,
     &goatstaken, move ) == FAILED )  exit( FAILED );
 
   /* Turn includes both human move and computer move */
   if ( (status=playOneTurn( &humanplayer, &skill, &round, boardarray, move, 
      complastmove, &goatstaken, &winFlag )) == INVALID_MOVE ) {
      sprintf( errormsg, "That wasn't a valid move for your gamepiece. "
                         "If you need to review the game movement "
                         "rules, you can click the directions/description "
                         "link back on the gameboard page, and then click "
                         "your browser's <CODE>Back</CODE> button when "
                         "finished to return to this point in the game.\n" );
      displayWWWError( errormsg );
      exit( FAILED );
   }
 
   /* Output the MIME-formatted HTML output that will go to the browser */
   outputHTMLpage( humanplayer, skill, round, boardarray, complastmove,
      goatstaken, winFlag );


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

