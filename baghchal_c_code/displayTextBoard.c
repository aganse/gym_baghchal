#include "baghChal.h"
#include <stdio.h>

int displayTextBoard(char humanplayer, int skill, int round,
   int boardarray[25], int complastmove[2], int goatstaken) {

   /* function prototypes */
   int moveArray2Str ( char *moveString, int *move );

   char piece[] = {'.','T','G'}, compLastMoveStr[]="[none]";
   moveArray2Str( compLastMoveStr, complastmove );

   printf("\n");
   printf("    A     B     C     D     E\n");
   printf("                                     Round %d\n", round);
   printf("1   %c --- %c --- %c --- %c --- %c        You are the %s.\n",
      piece[boardarray[0]], piece[boardarray[1]], piece[boardarray[2]], 
      piece[boardarray[3]], piece[boardarray[4]], 
      (humanplayer=='T')?"tiger player (T)":"goat player (G)" );
   printf("    | \\   |   / | \\   |   / |        You are at skill level %d.\n",
      skill );
   printf("    |   \\ | /   |   \\ | /   |        \n");
   printf("2   %c --- %c --- %c --- %c --- %c        # of goats taken: %d\n",
      piece[boardarray[5]], piece[boardarray[6]], piece[boardarray[7]], 
      piece[boardarray[8]], piece[boardarray[9]], goatstaken );
   printf("    |   / | \\   |   / | \\   |        Computer's last move was "
      "%s\n", compLastMoveStr );
   printf("    | /   |   \\ | /   |   \\ |        \n");
   printf("3   %c --- %c --- %c --- %c --- %c        \n",
      piece[boardarray[10]], piece[boardarray[11]], piece[boardarray[12]], 
      piece[boardarray[13]], piece[boardarray[14]] );
   printf("    | \\   |   / | \\   |   / |        \n");
   printf("    |   \\ | /   |   \\ | /   |        \n");
   printf("4   %c --- %c --- %c --- %c --- %c        \n",
      piece[boardarray[15]], piece[boardarray[16]], piece[boardarray[17]], 
      piece[boardarray[18]], piece[boardarray[19]] );
   printf("    |   / | \\   |   / | \\   |        \n");
   printf("    | /   |   \\ | /   |   \\ |        \n");
   printf("5   %c --- %c --- %c --- %c --- %c        \n",
      piece[boardarray[20]], piece[boardarray[21]], piece[boardarray[22]], 
      piece[boardarray[23]], piece[boardarray[24]] );

   return SUCCESSFUL;
}

