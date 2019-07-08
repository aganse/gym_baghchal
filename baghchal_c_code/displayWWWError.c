#include <stdio.h>
#include "baghChal.h"

int displayWWWError(char errormsg[]) {
    printf("Content-type: text/html\n\n");
    printf("<HTML>\n\n");
    printf(" <HEAD>\n");
    printf("  <TITLE>Invalid Input for Bagh Chal Game</TITLE>\n");
    printf(" </HEAD>\n\n");
    printf(" <BODY TEXT=\"#000000\">\n");   
    printf(" <CENTER>\n");
    printf(" <H1>Invalid Input<BR>\n");
    printf(" <SMALL>for Bagh Chal game:</SMALL></H1>\n");
    printf(" %s <P>\n", errormsg);
    printf(" <H2>(Now click your browser's BACK button so you can fix your ");
    printf("     input where you left off in the game.)</H2>\n");
    printf(" </CENTER>\n");
    printf(" </BODY>\n");
    printf("</HTML>\n");
  return SUCCESSFUL;
}
