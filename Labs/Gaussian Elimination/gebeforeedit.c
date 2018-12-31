//
//  gebeforeedit.c
//  Lab 8
//
//  Created by Chenqi Li on 2018/11/8.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

int ge_fw(float *matrix, int rows, int cols, float *matrix_out);
int ge_bw(float *matrix, int rows, int cols, float *matrix_out);


int main(void) {
   float matrix[16] = {0, -2, 1, 3, 3, 2, 11, 5, 1000, 3, 5, 10, 2, 7, 1, 8};
   float matrix_out[16] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
   ge_fw(matrix, 4, 4, matrix_out);
   
}


int ge_fw(float *matrix, int rows, int cols, float *matrix_out) {
   
   //Initialize *matrix_out, i
   matrix_out = (float *)malloc(rows*sizeof(int));
   int i = 0;
   int j = 0;
   float temp = 0;
   float multiple = 0.0;
   int cnt = 0;

   //Matrix_out set
   for(i=0;i<rows;i=i+1){
      for(j=0;j<cols;j++) {
         matrix_out[i*cols+j]=matrix[i*cols+j];
      }
   }
   

   
   
   
   //Check if first row first column is 0, switch
   if (matrix[0] == 0){
      //Check for first non-zero row
      for (i=1;i<rows;i++) {
         if (matrix[i*cols + 0] != 0) {
            //Swap rows
            for (j=0;j<cols;j++) {
               temp = matrix[i*cols + j];
               matrix[i*cols + j] = matrix[0+j];
               matrix[0+j] = temp;
            }
         }
      }
   }
   
   //Make rest of column to 0
   for (i=1;i<rows;i++) {
      if (matrix[i*cols + 0] != 0) {
         multiple = -(matrix[i*cols + 0]/matrix[0*cols + 0]);
         for (j=0;j<cols;j++) {
            matrix[i*cols + j] += multiple*matrix[0*cols + j];
         }
      }
   }
   

   
   //TEST initial
   for (i=0;i<rows;i++) {
      for (j=0;j<cols;j++) {
         printf("%8.3f ", matrix_out[i*cols + j]);
      }
      printf("\n");
   }
   printf("\n");
   
   //Set to matrix_out
   for (i=0;i<rows;i++) {
      for (j=0;j<cols;j++) {
         matrix_out[(i+cnt)*cols + (j+cnt)] = matrix[i*cols + j];
      }
   }
   
   
   
   //TEST final
   for (i=0;i<rows;i++) {
      for (j=0;j<cols;j++) {
         printf("%8.3f ", matrix_out[i*cols + j]);
      }
      printf("\n");
   }
   
   //Restate row and column number and counter
   rows -= 1;
   cols -= 1;
   cnt += 1;
   
   
   return 0;
}

