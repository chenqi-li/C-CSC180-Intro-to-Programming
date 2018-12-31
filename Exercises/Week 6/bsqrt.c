//
//  bsqrt.c
//  Week 6 Exercises
//
//  Created by Chenqi Li on 2018/11/13.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

float bsqrt(float acc, float square) {
   float est=0;
   est = square/2;
   while (abs((est*est)-square)>acc) {
      est = (est + square/est)/2;
   }
   return est;
}

int main(void) {
   printf("ans: %f\n", bsqrt(0.00001, 10));
}
