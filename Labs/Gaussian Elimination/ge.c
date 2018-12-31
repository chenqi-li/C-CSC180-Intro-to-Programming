//
//  ge.c
//  Lab 8
//
//  Created by Chenqi Li on 2018/11/8.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

int ge_fw(float *matrix, int rows, int cols, float *matrix_out);
int ge_bw(float *matrix, int rows, int cols, float *matrix_out);


int main(void) {
   float matrix[16] = {0, -2, 1, 3, 3, 2, 11, 5, 1000, 3, 5, 10};
   float matrix_out[16];
   int i = 0;
   int j = 0;
   int cols=4;
   int rows=3;
   ge_fw(matrix, 3, 4, matrix_out);
   //TEST final
   for (i=0;i<rows;i++) {
      for (j=0;j<cols;j++) {
         printf("%8.3f ", matrix[i*cols + j]);
      }
      printf("\n");
   }
   
}


int ge_fw(float *matrix, int rows, int cols, float *matrix_out) {

   
   //Initialize *matrix_out, i
   matrix_out = matrix;
   int i = 0;
   int j = 0;
   float temp = 0;
   float multiple = 0.0;
   
   int cnt = 0;
   int st = 0;
   
   
   while (st<rows){
      //Check if first row first column is 0, switch
      if (matrix[st*cols + st] == 0){
         //Check for first non-zero row
         for (i=st+1;i<rows;i++) {
            if (matrix[i*cols + st] != 0) {
               //Swap rows
               for (j=st;j<cols;j++) {
                  temp = matrix[i*cols + j];
                  matrix[i*cols + j] = matrix[st+j];
                  matrix[st+j] = temp;
               }
            }
         }
      }
      
      
      
      //Make rest of column to 0
      for (i=st+1;i<rows;i++) {
         if (matrix[i*cols + st] != 0) {
            multiple = -(matrix[i*cols + st]/matrix[st*cols + st]);
            for (j=st;j<cols;j++) {
               matrix[i*cols + j] += multiple*matrix[st*cols + j];
            }
         }
      }
      
      
      //Set to matrix_out
      for (i=st;i<rows;i++) {
         for (j=st;j<cols;j++) {
            matrix_out[i*cols + j] = matrix[i*cols + j];
         }
      }
      


      //Restate row and column number and counter
      st += 1;
      cnt += 1;
   }
   return 0;
}

