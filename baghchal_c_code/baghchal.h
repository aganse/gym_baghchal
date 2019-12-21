/* baghChal.h : header file for baghchal game */

#define SUCCESSFUL 0
#define FAILED 1
#define WINNER 2
#define GAME_OVER 3
#define INVALID_MOVE 4

#define NULLPOS 99
#define MAX_GOATS_TAKEN 5  /*some prefer 20 (all goats) but that's a long game*/

#define EMPTYPIC "bc_empty.jpg"
#define TIGERPIC "bc_tiger.jpg"
#define GOATPIC "bc_goat.jpg"
#define TOPPIC "bc_top.jpg"
#define BOTTOMPIC "bc_bottm.jpg"
#define CROSSPIC "bc_cross.jpg"
#define LEFT1PIC "bc_left1.jpg"
#define LEFT2PIC "bc_left2.jpg"
#define LEFT3PIC "bc_left3.jpg"
#define LEFT4PIC "bc_left4.jpg"
#define LEFT5PIC "bc_left5.jpg"
#define RIGHTPIC "bc_right.jpg"
#define FILL1PIC "bc_fill1.jpg"
#define FILL2PIC "bc_fill2.jpg"
#define BC_PATH "http://www.mysite.com/~myaccount/baghchal/"
#define DIRECTIONS_FILE "baghchal.htm"
#define NEWGAME_FILE "bc_init.htm"
#define QUIT_URL "http://www.mysite.com/~myaccount/projects.htm"
#define BC_CGI_PATH "http://www.mysite.com/~myaccount/cgi-bin/baghchal"

struct moveto {
  int Pos;
  int CanJumpToPos;
};

struct boardpoint {
  int NumCanMoveTo;
  struct moveto CanMoveTo[8];
} GameBoardPos[25];


/* function prototypes */
int initGameMovementRules();
int playOneTurn( char *humanplayer, int *skill, int *round, int *boardarray,
   int *move, int *complastmove, int *goatstaken, int *winFlag );
int moveStr2Array( char *moveString, int *move, int moveStringLen );
int invalidMoveEntry( char *moveString );
int validateParams( char *inputline, char *humanplayer, int *skill,
   int *round, int boardarray[25], int *goatstaken, int move[2] );
int outputHTMLpage(char player, int skill, int round, int boardarray[25],
   int complastmove[2], int goatstaken, int winFlag);
int outputString(char player, int skill, int round, int boardarray[25],
   int complastmove[2], int goatstaken, int winFlag);
int displayTextBoard(char humanplayer, int skill, int round,
   int boardarray[25], int complastmove[2], int goatstaken);
