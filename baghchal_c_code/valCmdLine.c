#include <stdio.h>
#include <string.h>
#include "baghChal.h"
#define displayWWWError printf


/* for validating command line params, NOT player moves... */
int validateParams(char StdinString[], char *player, int *skill, int *round, int boardarray[25], int *goatstaken, int move[2]) {

  char tmp[20]="", errormsg[400], moveString[6]="";
  int i;

  /*int displayWWWError( char *errormsg );*/
  int moveStr2Array ( char *moveString, int *move, int moveStringLen );



  /* verify param list: */

  if (strlen(StdinString) > 91) {
    sprintf(errormsg, "Data error : commandline is too long. <BR>\n");
    strcat(errormsg, "(Are you trying to hack my game? ;)\n");
    displayWWWError(errormsg);
    return FAILED;
  }

  strncat(tmp,StdinString,7);
  if ( !strcmp(tmp,"player=") && 
       (StdinString[7]=='T' || StdinString[7]=='G') &&
       StdinString[8]=='&')
    *player=StdinString[7];
  else {
    sprintf(errormsg, "Data error : ");
    strcat(errormsg, "first param in StdinString not player=[TorG]. <BR>\n");
    strcat(errormsg, "(Are you trying to hack my game? ;)\n");
    displayWWWError(errormsg);
    return FAILED;
  }

  for (i=0; i<9; i++, StdinString++); /* shift to next param in StdinString*/
  tmp[0]='\0';

  strncat(tmp,StdinString,6);
  if ( !strcmp(tmp,"skill=") && 
       (StdinString[6]=='1' || StdinString[6]=='2' || StdinString[6]=='3') &&
       StdinString[7]=='&')
    /* converting char ascii value to numerical value */
    *skill=StdinString[6]-'0';   /* convert ascii value to actual number */
  else {
    sprintf(errormsg, "Data error : ");
    strcat(errormsg, "second param in StdinString not skill=[1,2,3]. <BR>\n");
    strcat(errormsg, "(Are you trying to hack my game? ;)\n");
    displayWWWError(errormsg);
    return FAILED;
  }

  for (i=0; i<8; i++, StdinString++); /* shift to next param in StdinString*/
  tmp[0]='\0';

  strncat(tmp,StdinString,6);
  if ( !strcmp(tmp,"round=") && 
       StdinString[6]>='0' && StdinString[6]<='9' &&
       StdinString[7]>='0' && StdinString[7]<='9' &&
       StdinString[8]>='0' && StdinString[8]<='9' &&
       StdinString[9]=='&' )
    /* (it was a toss-up here whether to do this or convert to str & use atoi)*/
    *round=(StdinString[6]-'0')*100 +
           (StdinString[7]-'0')*10 + 
           (StdinString[8]-'0');
  else {
    sprintf(errormsg, "Data error : ");
    strcat(errormsg, "third param in StdinString not round=[3digits]. <BR>\n");
    strcat(errormsg, "(Are you trying to hack my game? ;)\n");
    displayWWWError(errormsg);
    return FAILED;
  }

  for (i=0; i<10; i++, StdinString++); /*shift to next param in StdinString*/
  tmp[0]='\0';

  strncat(tmp,StdinString,11);
  if ( !strcmp(tmp,"boardarray=") && 
   (StdinString[11]=='0'||StdinString[11]=='1'||StdinString[11]=='2')&&
   (StdinString[12]=='0'||StdinString[12]=='1'||StdinString[12]=='2')&&
   (StdinString[13]=='0'||StdinString[13]=='1'||StdinString[13]=='2')&&
   (StdinString[14]=='0'||StdinString[14]=='1'||StdinString[14]=='2')&&
   (StdinString[15]=='0'||StdinString[15]=='1'||StdinString[15]=='2')&&
   (StdinString[16]=='0'||StdinString[16]=='1'||StdinString[16]=='2')&&
   (StdinString[17]=='0'||StdinString[17]=='1'||StdinString[17]=='2')&&
   (StdinString[18]=='0'||StdinString[18]=='1'||StdinString[18]=='2')&&
   (StdinString[19]=='0'||StdinString[19]=='1'||StdinString[19]=='2')&&
   (StdinString[20]=='0'||StdinString[20]=='1'||StdinString[20]=='2')&&
   (StdinString[21]=='0'||StdinString[21]=='1'||StdinString[21]=='2')&&
   (StdinString[22]=='0'||StdinString[22]=='1'||StdinString[22]=='2')&&
   (StdinString[23]=='0'||StdinString[23]=='1'||StdinString[23]=='2')&&
   (StdinString[24]=='0'||StdinString[24]=='1'||StdinString[24]=='2')&&
   (StdinString[25]=='0'||StdinString[25]=='1'||StdinString[25]=='2')&&
   (StdinString[26]=='0'||StdinString[26]=='1'||StdinString[26]=='2')&&
   (StdinString[27]=='0'||StdinString[27]=='1'||StdinString[27]=='2')&&
   (StdinString[28]=='0'||StdinString[28]=='1'||StdinString[28]=='2')&&
   (StdinString[29]=='0'||StdinString[29]=='1'||StdinString[29]=='2')&&
   (StdinString[30]=='0'||StdinString[30]=='1'||StdinString[30]=='2')&&
   (StdinString[31]=='0'||StdinString[31]=='1'||StdinString[31]=='2')&&
   (StdinString[32]=='0'||StdinString[32]=='1'||StdinString[32]=='2')&&
   (StdinString[33]=='0'||StdinString[33]=='1'||StdinString[33]=='2')&&
   (StdinString[34]=='0'||StdinString[34]=='1'||StdinString[34]=='2')&&
   (StdinString[35]=='0'||StdinString[35]=='1'||StdinString[35]=='2')&&
   StdinString[36]=='&') {
   for(i=0;i<25;i++) boardarray[i]=StdinString[i+11]-'0'; /*conv ascii to int*/
  }
  else {
    sprintf(errormsg, "Data error : ");
    strcat(errormsg,
    "fourth param in StdinString not boardarray=[25digits of 0,1,or2]. <BR>\n");
    strcat(errormsg, "(Are you trying to hack my game? ;)\n");
    displayWWWError(errormsg);
    return FAILED;
  }

  for (i=0; i<37; i++, StdinString++); /* shift to next param in StdinString*/
  tmp[0]='\0';

  strncat(tmp,StdinString,11);
  if ( !strcmp(tmp,"goatstaken=") && 
       StdinString[11]>='0' && StdinString[11]<='9' &&
       StdinString[12]>='0' && StdinString[12]<='9' &&
       StdinString[13]=='&' )
    /* (it was a toss-up here whether to do this or convert to str & use atoi)*/
    *goatstaken=(StdinString[11]-'0')*10 +
           (StdinString[12]-'0');
  else {
    sprintf(errormsg, "Data error : ");
    strcat(errormsg, "fifth param in StdinString not goatstaken=[2digits]. <BR>\n");
    strcat(errormsg, "(Are you trying to hack my game? ;)\n");
    displayWWWError(errormsg);
    return FAILED;
  }

  for (i=0; i<14; i++, StdinString++); /*shift to next param in StdinString*/
  tmp[0]='\0';


  strcat(StdinString,"-----");  /* can do this cuz 'move=' is last param */
  strncat(tmp,StdinString,5);
  if ( !strcmp(tmp,"move=") && 
       StdinString[5]>='a' && StdinString[5]<='e' &&
       StdinString[6]>='1' && StdinString[6]<='5' &&
       (StdinString[7]=='%' || StdinString[7]=='-') &&
       (StdinString[8]=='2' || StdinString[8]=='-') &&
       (StdinString[9]=='C'||StdinString[9]=='c'||StdinString[9]=='-')
       && ( (StdinString[10]>='a' && StdinString[10]<='e') || 
            (StdinString[10]=='-') )
       && ( (StdinString[11]>='1' && StdinString[11]<='5') || 
            (StdinString[11]=='-') )    ) {

    /* convert 'move' segment of StdinString to move[] array */
    strncat(moveString,StdinString+5,2);
    if(strncmp(StdinString+7, "-----", 5)) {
      strcat(moveString,",");
      strncat(moveString,StdinString+10,2);
    }
    moveStr2Array(moveString, move, strlen(moveString) );

  }
  else {
    sprintf(errormsg, "The <B>move</B> value you enter must look like "
              "<B><I>a3,b4</I></B> or <B><I>d5</I></B>. <BR>\n"
              "Note the letters must be the alphabet letters a-e and "
              "the numbers must be 1-5,<BR>\n"
              "which match up with the letters and numbers along the side of "
              "the gameboard.<BR>\n"
              "NOTE THAT FOR NOW THE LETTERS MUST BE LOWERCASE.<BR>\n" );
    displayWWWError(errormsg);
    return FAILED;
  }

return SUCCESSFUL;
}
