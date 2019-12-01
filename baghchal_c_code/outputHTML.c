#include <stdio.h>
#include "baghchal.h"

int outputHTMLpage(char player, int skill, int round, int boardarray[25],
                    int complastmove[2], int goatstaken, int winFlag) {

  int i;
  char *Piece[]={ BC_PATH EMPTYPIC, BC_PATH TIGERPIC, BC_PATH GOATPIC };
  char compLastMoveStr[]="[none]";

  int moveStr2Array ( char *moveString, int *move, int moveStringLen );
  int moveArray2Str ( char *moveString, int *move );



  moveArray2Str( compLastMoveStr, complastmove );

  printf("Content-type: text/html\n\n");
  printf("<HTML>\n\n");
  printf("<HEAD>\n");
  printf("<TITLE>Bagh Chal</TITLE>\n");
  printf("</HEAD>\n\n");
  printf("<BODY BGCOLOR=white>\n\n");
  printf("<TABLE ALIGN=center WIDTH=\"100%%\"><TR>\n\n");
  printf("<TD VALIGN=top WIDTH=\"50%%\">\n");
  printf("  <CENTER>\n");
  printf("  <H1>Bagh Chal<BR>\n");
  printf("  <FONT SIZE=2>The National Game of Nepal</FONT></H1>\n");
  printf("  <HR WIDTH=\"90%%\">\n");
  printf("  <A HREF=\"%s\">\n", BC_PATH DIRECTIONS_FILE);
  printf("    Read directions / description of game.</A>\n");
  printf("  <BR>\n");
  printf("  <A HREF=\"%s\">\n", BC_PATH NEWGAME_FILE);
  printf("    Start a new game.</A>\n");
  printf("  <BR>\n");
  printf("  <A HREF=\"%s\">\n", QUIT_URL);
  printf("    Quit and return to Projects page.</A>\n");
  printf("  <BR>\n");
  printf("  <HR WIDTH=\"90%%\">\n");
  printf("  </CENTER>\n\n");
  printf("</TD>\n\n");
  printf("<TD ROWSPAN=2 WIDTH=\"50%%\" VALIGN=bottom>\n");
  printf("<P><BR>\n\n");

  printf("<!-- Playing board -->\n");
  printf("<TABLE CELLPADDING=0 CELLSPACING=0 BORDER=0 ALIGN=center>\n");

  printf("<TR>\n");
  printf(" <TD COLSPAN=11>\n");
  printf("  <IMG SRC=\"%s\"\n", BC_PATH TOPPIC);
  printf("     HEIGHT=20 WIDTH=320></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH LEFT1PIC);
  printf("    HEIGHT=20 WIDTH=20></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[0]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[1]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[2]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[3]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[4]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH RIGHTPIC);
  printf("    HEIGHT=20 WIDTH=6></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf(" <TD COLSPAN=11>\n");
  printf("  <IMG SRC=\"%s\"\n", BC_PATH FILL1PIC);
  printf("     HEIGHT=48 WIDTH=320></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH LEFT2PIC);
  printf("    HEIGHT=20 WIDTH=20></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[5]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[6]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[7]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[8]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[9]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH RIGHTPIC);
  printf("    HEIGHT=20 WIDTH=6></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf(" <TD COLSPAN=11>\n");
  printf("  <IMG SRC=\"%s\"\n", BC_PATH FILL2PIC);
  printf("     HEIGHT=48 WIDTH=320></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH LEFT3PIC);
  printf("    HEIGHT=20 WIDTH=20></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[10]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[11]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[12]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[13]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[14]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH RIGHTPIC);
  printf("    HEIGHT=20 WIDTH=6></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf(" <TD COLSPAN=11>\n");
  printf("  <IMG SRC=\"%s\"\n", BC_PATH FILL1PIC);
  printf("     HEIGHT=48 WIDTH=320></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH LEFT4PIC);
  printf("    HEIGHT=20 WIDTH=20></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[15]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[16]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[17]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[18]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[19]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH RIGHTPIC);
  printf("    HEIGHT=20 WIDTH=6></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf(" <TD COLSPAN=11>\n");
  printf("  <IMG SRC=\"%s\"\n", BC_PATH FILL2PIC);
  printf("     HEIGHT=48 WIDTH=320></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH LEFT5PIC);
  printf("    HEIGHT=20 WIDTH=20></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[20]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[21]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[22]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[23]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH CROSSPIC);
  printf("    HEIGHT=20 WIDTH=46></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", Piece[boardarray[24]]);
  printf("    HEIGHT=20 WIDTH=22></TD>\n");
  printf("<TD>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH RIGHTPIC);
  printf("    HEIGHT=20 WIDTH=6></TD>\n");
  printf("</TR>\n");

  printf("<TR>\n");
  printf("<TD COLSPAN=11>\n");
  printf(" <IMG SRC=\"%s\"\n", BC_PATH BOTTOMPIC);
  printf("    HEIGHT=10 WIDTH=320></TD>\n");
  printf("</TR>\n");

  printf("</TABLE>\n\n");
  printf("</TR>\n\n");

  printf("<TR>\n");
  printf("<TD VALIGN=bottom>\n");
  printf("<FORM METHOD=POST ");
  printf("ACTION=\"" BC_CGI_PATH "\">\n");
  printf("  <input type=hidden name=player value=\"%c\">\n", player);
  printf("  <input type=hidden name=skill value=\"%d\">\n", skill);
  printf("  <input type=hidden name=round value=\"%.3d\">\n", round);
  printf("  <input type=hidden name=boardarray value=\"");
  for(i=0;i<25;i++) printf("%d", boardarray[i]);
  printf("\">\n");
  printf("  <input type=hidden name=goatstaken value=\"%.2d\">\n",goatstaken);
  printf("  Round %d.<BR>\n", round);
  printf("  You are the %s player.<BR>\n", (player=='T')?"tiger":"goat" );
  printf("  %d goats have been taken by tiger.<P>\n", goatstaken );
  printf("  <B>Computer just moved as %s: %s</B><BR>\n",
    (player=='T')?"goat":"tiger", compLastMoveStr );
  if(winFlag) {
    printf("<BIG><BIG><B>%s Won!!!</B></BIG></BIG><BR>",
      (player=='T')?"Tiger":"Goat");
  }
  else {
    printf("  <B>Enter your move:</B>\n");
    printf("  <INPUT TYPE=text NAME=move SIZE=10>\n");
    printf("  <INPUT TYPE=submit VALUE=\"Go\">\n");
    printf("<BR><SMALL><I>( Examples:</I> e5,d4 <I> for tiger, or </I> d1 \n");
    printf("                   <I>or</I> c3,b4 <I>for goat...)</I></SMALL>\n");
    printf("</FORM>\n");
  }
  printf("</TD>\n");
  printf("</TR>\n\n");

  printf("<TR>\n");
  printf("<TD COLSPAN=2 VALIGN=bottom>\n");
  printf(" <CENTER><SMALL>\n");
  printf(" <BR>\n");
  printf(" This webpage, program, and all icons Copyright 1999 by\n");
  printf(" Andrew Ganse. All rights reserved.\n");
  printf(" </SMALL></CENTER>\n");
  printf("</TD>\n");
  printf("</TR>\n");

  printf("</TABLE>\n\n");
  printf("</BODY>\n\n");
  printf("</HTML>\n");

return SUCCESSFUL;
}

