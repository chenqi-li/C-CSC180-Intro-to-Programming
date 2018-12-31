//
//  hwsqrt.c
//  Week 6 Exercises
//
//  Created by Chenqi Li on 2018/11/13.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

float bsqrt(float, float);

int main(void) {
   float i;
   for(i=0;i<10;i++){
      float sqrt=0;
      sqrt = bsqrt(i,0.001);
      printf("Hello world;  %f sqrt is %f\n",i,sqrt);
   }
   return 0; }



float bsqrt(float square, float acc) {
   float est=0;
   est = square/2;
   while (abs((est*est)-square)>acc) {
      est = (est + square/est)/2;
   }
   return est;
}
