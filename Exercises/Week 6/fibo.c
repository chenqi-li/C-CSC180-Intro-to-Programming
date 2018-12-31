//
//  fibo.c
//  Week 6 Exercises
//
//  Created by Chenqi Li on 2018/11/13.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

int main(void) {
   int i = 0;
   for (i=0;i<20;i++) {
      printf("fibo %d is %d\n", i, fibo(i));
   }
   
   i = 0;
   for (i=0;i<20;i++) {
      printf("fibor %d is %d\n", i, fibor(i));
   }
}

int fibo(int n) {
   int old = 1;
   int oldold = 1;
   int i;

   
   for (i=0;i<n;i++) {
      int temp = old;
      old = old + oldold;
      oldold = temp;
   }
   return oldold;

}

int fibor(int n) {
   if (n==0) {
      return 1;
   }
   else if (n==1) {
      return 1;
   }
   else {
      return fibor(n-1)+fibo(n-2);
   }
}
