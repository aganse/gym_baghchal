#include "baghchal.h"
#include <stdio.h>
#include <string.h>

int moveStr2Array ( char *moveString, int *move, int moveStringLen ) {

   /* converting ascii 'a'-'e' and '1'-'5' */
   move[0] = (moveString[0]-'a') + (moveString[1]-'1') * 5;

   if( moveStringLen == 5 )
      move[1] = (moveString[3]-'a') + (moveString[4]-'1') * 5;
   else if( moveStringLen == 2 ) move[1] = -1;
   else return FAILED;

   return SUCCESSFUL;

}


int moveArray2Str ( char *moveString, int *move ) {

   if( move[0]==-1 && move[1]==-1 ) strcpy(moveString,"[none]");
   else {
      /* converting to ascii 'a'-'e' and '1'-'5' */
      moveString[0] = (move[0]%5)+'a';
      moveString[1] = (move[0]/5)+'1';  /* relying on int div to truncate */
   
      if( move[1] == -1 )
         moveString[2] = moveString[3] = moveString[4] = moveString[5] = 0;
      else if( move[1] < 25 ) {
         moveString[2] = ',';
         moveString[3] = (move[1]%5)+'a';
         moveString[4] = (move[1]/5)+'1';  /* relying on int div to truncate */
         moveString[5] = 0;
      }
      else return FAILED;
   }
   
   return SUCCESSFUL;

}
