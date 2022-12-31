#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "CStuff.h"
#include "cartwheel.h"
       
/*
  warning, no error checks
*/
int main(int argc, char** argv) { 

  char        buffer[1024];
  int         inputfd;
  FILE *      outputfd;
  int         cnt;
  cartWheel_t w;
  
 
  if ((inputfd = open(argv[1], ( O_RDWR | O_NONBLOCK ))) == -1) {
    printf("input open error\n");
    return -1;
  }
  
  if ((outputfd = fopen(argv[2], "w+")) == NULL) {
    printf("output open error\n");
    return -1;
  }
  
  cartWheelInit(&w);
  setCartWheelType(&w, 0);
    
 // printf("Waiting for data...\n");
  
  for (cnt = 0; cnt == 0; ioctl(inputfd, FIONREAD, &cnt)) {
   printf("Waiting for data... %c\r", cartWheelTurn(&w)); fflush(stdout);
   sleep(1);
  }  
  
  
  printf ("File being recieved...\n");
  
  do {
  
    ioctl ( inputfd, FIONREAD, &cnt);
    read  ( inputfd, buffer,   Min(1024, cnt));
    fwrite( buffer,  1,        Min(1024, cnt), outputfd);
    usleep( 62500);                                       // can keep up with 115200
    printf( "="); fflush(stdout);
    
  } while(cnt != 0);
  
  printf("RX complete.\n");

  close (inputfd);
  fclose (outputfd);
  
  
  return 0;
}
