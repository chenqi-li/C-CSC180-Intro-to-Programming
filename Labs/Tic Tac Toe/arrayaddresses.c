//
//  arrayaddresses.c
//  Lab 7
//
//  Created by Chenqi Li on 2018/10/31.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>



int main(void) {
   int a[10];
   int i;

   printf("the size of an integer in my version of C is %d\n", sizeof(int));
   printf("a is %d\n",a);
   for (i=0;i<10;i=i+1){
      printf(" the ADDRESS OF a[%d] is %d\n",i, &(a[i]));
   }
   return 0;
}


