
#ifndef __cartwheel
#define __cartwheel

  typedef struct cartWheel_s {
     unsigned char i;
     unsigned char type;
  } cartWheel_t;


  int cartWheelInit(cartWheel_t * this) ;
  int cartWheelFini(cartWheel_t * this) ;
  int setCartWheelType(cartWheel_t * this, int type);
  char cartWheelTurn(cartWheel_t * this) ;
 
#endif
