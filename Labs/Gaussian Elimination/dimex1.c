//
//  dimex1.c
//  Lab 8
//
//  Created by Chenqi Li on 2018/11/6.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>



int main(void) {
   int array[3][3];
   int x,y;
   int i = 0;
   for(x=0;x<3;x++) {
      for(y=0;y<3;y++) {
         array[x][y] = i;
         i = i+1;
         //printf("%d\n", i);
      }
   }
   
   for (x=0;x<3;x++) {
      for (y=0;y<3;y++) {
         printf("%3d ", array[x][y]);
      }
      printf("\n");
   }
}



