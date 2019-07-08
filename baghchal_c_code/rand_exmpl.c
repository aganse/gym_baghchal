#include <stdlib.h>
#include <stdio.h>
#include <time.h>

main () {
 int m=15;
 int r,i;

 srand(time(NULL) % 32767);

 for(i=0;i<5;i++) {
  r=1+(int) m*(rand()/(RAND_MAX+1.0));
  printf("Our random number between 0 and %d is %d.\n", m, r);
 }
}


