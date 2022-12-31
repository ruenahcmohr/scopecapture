#include "cartwheel.h"

char * CARTWHEELS[] = {"|/-\\", ".oOo", ")|(|", "]_L^", "'-. " };

int cartWheelInit(cartWheel_t * this) {
  if (this) {
    this->type = 0;
    this->i = 0;
    return 0;
  }
  return 1;
}

int cartWheelFini(cartWheel_t * this) {
 if (this) return 0;
 else      return 1;
}

int setCartWheelType(cartWheel_t * this, int type) {
  if ((type >= 0) & (type <=3)) {
    this->type = type;
    return 0;
  }
  return 1;
}

char cartWheelTurn(cartWheel_t * this) {
  
  this->i++;
  
  if (!CARTWHEELS[this->type][this->i])
   this->i = 0;
  
  return(CARTWHEELS[this->type][this->i]);
}

/*

#include <stdio.h>

int main(void) {

  cartWheel_t w;
  int i;
  
  cartWheelInit(&w);
  setCartWheelType(&w, 1);
  
  for (i = 0; i < 200; i++) {
    printf("  %c\r", cartWheelTurn(&w));
    fflush(stdout);
    usleep(125000);  
  }
  
 return 0;
}

*/
