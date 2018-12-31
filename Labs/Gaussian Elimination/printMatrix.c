//
//  printMatrix.c
//  Lab 8
//
//  Created by Chenqi Li on 2018/11/6.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

int printMatrix(float *, int, int);

int main(void) {
   float array[9]={1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
   printMatrix(array,3,3);
}


int printMatrix(float *array, int rows, int cols) {
   int x=0,y=0;
   
   for(x=0;x<rows;x++) {
      for(y=0;y<cols;y++) {
         printf("%4f ", array[x*cols+y]);
      }
      printf("\n");
   }
   return 0;
}
