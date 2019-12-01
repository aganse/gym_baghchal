#include "baghchal.h"
#include <stdio.h>

int initGameMovementRules() {

  int i, j, k;

  /* Describe boardlayout & movement rules in arrays that will fill in the
     above structures - these values are constant and inherent to game
     (ie, piece values not assigned here) */
  char NumCanMoveToArray[25] = {3,3,5,3,3,
                                3,8,4,8,3,
                                5,4,8,4,5,
                                3,8,4,8,3,
                                3,3,5,3,3 };
  char MoveJumpArray[][2] = {
    /* One line for each entry in NumCanMoveToArray (each boardpoint)... 
    from-pt   {move,jump} possibilities               ...(99=NULLPOS) */
    /* 0*/    {1,2}  ,{6,12} ,{5,10} ,
    /* 1*/    {2,3}  ,{6,11} ,{0,99} ,
    /* 2*/    {3,4}  ,{8,14} ,{7,13} ,{6,10} ,{1,0}  ,
    /* 3*/    {4,99} ,{8,13} ,{2,1}  ,
    /* 4*/    {9,14} ,{8,12} ,{3,2}  ,                      /* end of row 1 */
    /* 5*/    {0,99} ,{6,7}  ,{10,15},
    /* 6*/    {0,99} ,{1,99} ,{2,99} ,{7,8}  ,{12,18},{11,16},{10,99},{5,99} ,
    /* 7*/    {2,99} ,{8,9}  ,{12,17},{6,5}  ,
    /* 8*/    {2,99} ,{3,99} ,{4,99} ,{9,99} ,{14,99},{13,18},{12,16},{7,6}  ,
    /* 9*/    {4,99} ,{14,19},{8,7}  ,                      /* end of row 2 */
    /*10*/    {5,0}  ,{6,2}  ,{11,12},{16,22},{15,20},
    /*11*/    {6,1}  ,{12,13},{16,21},{10,99},
    /*12*/    {6,0}  ,{7,2}  ,{8,4}  ,{13,14},{18,24},{17,22},{16,20},{11,10},
    /*13*/    {8,3}  ,{14,99},{18,23},{12,11},
    /*14*/    {9,4}  ,{19,24},{18,22},{13,12},{8,2}  ,      /* end of row 3 */
    /*15*/    {10,5} ,{16,17},{20,99},
    /*16*/    {10,99},{11,6} ,{12,8} ,{17,18},{22,99},{21,99},{20,99},{15,99},
    /*17*/    {12,7} ,{18,19},{22,99},{16,15},
    /*18*/    {12,6} ,{13,8} ,{14,99},{19,99},{24,99},{23,99},{22,99},{17,16},
    /*19*/    {14,9} ,{24,99},{18,17},                      /* end of row 4 */
    /*20*/    {15,10},{16,12},{21,22},
    /*21*/    {20,99},{16,11},{22,23},
    /*22*/    {21,20},{16,10},{17,12},{18,14},{23,24},
    /*23*/    {22,21},{18,13},{24,99},
    /*24*/    {23,22},{18,12},{19,14}
    };

  /* Fill GameBoard structure with movement rules from the arrays */
  for (i=0; i<25; i++) GameBoardPos[i].NumCanMoveTo = NumCanMoveToArray[i];
  for (i=0, k=0; i<25; i++) {
    for (j=0; j<GameBoardPos[i].NumCanMoveTo; j++, k++) {
      GameBoardPos[i].CanMoveTo[j].Pos = MoveJumpArray[k][0];
      GameBoardPos[i].CanMoveTo[j].CanJumpToPos = MoveJumpArray[k][1];
    }
  }
return SUCCESSFUL;
}


int TestPrintGameBoard() {     /* (just for double-checking layout array) */
  int i,j,k;
  for (i=0, k=0; i<25; i++) {
    for (j=0; j<GameBoardPos[i].NumCanMoveTo; j++, k++) {
      printf("GameBoardPos[%d].CanMoveTo[%d].Pos = %d\n", i, j,
              GameBoardPos[i].CanMoveTo[j].Pos);
      printf("GameBoardPos[%d].CanMoveTo[%d].CanJumpToPos = %d\n", i, j,
              GameBoardPos[i].CanMoveTo[j].CanJumpToPos);
    }
  }
return SUCCESSFUL;
}

