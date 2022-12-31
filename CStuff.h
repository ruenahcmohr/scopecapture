/*
   misc stuff that should exist anyhow.
   too old and too many authors to count.
*/
#ifndef __cstuff
#define __cstuff

#define _GNU_SOURCE
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>


// arg floating point numbers!
#define PRECISION 0.00000000001
#define FloatEqualish(A,B)     (InLimits(A, B-PRECISION, B+PRECISION))
#define FloatGreaterish(A,B)   (A>((B)+PRECISION))
#define FloatLessish(A,B)      (A<((B)-PRECISION))
#define FloatGOrEish(A,B)      (A>=((B)+PRECISION))
#define FloatLOrEish(A,B)      (A<=((B)-PRECISION))

#define EXIT_OK 1
#define EXIT_FAIL -1

#define IsHigh(BIT,BYTE)    ((BYTE & (1<<BIT)) != 0)
#define IsLow(BIT,BYTE)     ((BYTE & (1<<BIT)) == 0)
#define SetBit(BIT,BYTE)     BYTE |= (1<<BIT)
#define ClearBit(BIT,BYTE)   BYTE &= ~(1<<BIT)

#define ABS(a)                ((a) < 0 ? ((a)*(-1.0)) : (a))
#define SIGN(x)               ((x)==0?0:(x)>0?1:-1)
#define SQR(x)                ((x)*(x))

#define Limit(v,l,h)        (((v) > (h)) ? (h) : ((v) < (l)) ? (l) : (v))

#define InLimits(v,l,h)      (((v) > (h)) ? 0 : ((v) < (l)) ? 0 : 1)

#define InLimitsE(v,l,h)     InLimits(v,l,h)
#define InLimitsI(v,l,h)      (((v) >= (h)) ? 0 : ((v) <= (l)) ? 0 : 1)

// does a differ from b by more than D?
#define DiffGreater(a,b,D)        (ABS((a)-(b))>D? : 1 : 0)

// for linear remapping of number ranges, see arduino map()
// think of a line, between Il,Ol and Ih,Oh, this solves the y for given x position
#define RangeRemap(v,Il,Ih,Ol,Oh) (((((v)-(Il))*((Oh)-(Ol)))/((Ih)-(Il)))+(Ol))

#define Min(X,Y) (((X)<(Y))?(X):(Y))
#define Max(X,Y) (((X)>(Y))?(X):(Y))

// is Z within X and Y?
//  god... you would think it was lisp...
// inclusive and exclusive versions
#define WITHINI(X,Y,Z)  ( ( ((Z) >= Min((X),(Y))) & ((Z) <= Max((X),(Y))) ) ? (1):(0) )
#define WITHINE(X,Y,Z)  ( ( ((Z) > Min((X),(Y))) & ((Z) < Max((X),(Y))) ) ? (1):(0) )
// backwards compat.
#define WITHIN(X,Y,Z) WITHINI(X,Y,Z)

#define rad2deg(K) ((K)*(180.0/3.1415926535))
#define deg2rad(K) ((K)*(3.1415926535/180.0))

#define mm2inch(K) (K/25.4)
#define inch2mm(K) (K*25.4)

// ascii nibble to binary
#define ASCNibToBin(A) (((A)>'9')?((A)-'7'):((A)-'0'))
// low binary nibble to ascii
#define BinToASCNib(B) (((B)&0x0F)<9?((B)&0x0F)+'0':((B)&0x0F)+'7')

// convert X,Y to integer offset V, I is XMAX J is YMAX
// this is broken for 0 based arrays...
//#define xy2i(X,Y,I,J)  (((I)*(Y))+(X))
#define xy2i(X,Y,I)  (((I+1)*(Y))+(X))

#define i2x(V,J)   ((V)%(J+1))
#define i2y(V,J)   ((V)/(J+1))

// bounded number ramping
#define RampUp(k,top)  (((k)<(top))?(k++):(k+=0))
#define RampDown(k,bot) (((k)>(bot))?(k--):(k+=0))

// use stdbool.h !
typedef enum boolean_e { FALSE = 0, TRUE  } boolean_t;
#define stringTrueFalse(B) (((B) == 0)?"False":"True")

#define string_t char *



#endif
