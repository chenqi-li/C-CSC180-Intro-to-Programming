//
//  myAbs.c
//  Week 6 Exercises
//
//  Created by Chenqi Li on 2018/11/13.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>



float myAbs(float);

int main(void) {
   printf("ans: %f\n", myAbs(0));
}

float myAbs(float in) {
   if (in>0) {
      return in;
   }
   else if (in<0) {
      return -in;
   }
   else {
      return in;
   }
}
