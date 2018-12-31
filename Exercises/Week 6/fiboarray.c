//
//  fiboarray.c
//  Week 6 Exercises
//
//  Created by Chenqi Li on 2018/11/13.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

int main(void) {
   int N;
   printf("Enter a number: \n");
   scanf("%d", &N);
   int array[N];
   int i = 0;
   

   
   
   for (i=0;i<N;i++) {
      array[i] = fibo(i);
   }
   
   for (i=0;i<N;i++) {
      printf("array[%d] is %d\n", i, array[i]);
   }
   
   return 1;
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
