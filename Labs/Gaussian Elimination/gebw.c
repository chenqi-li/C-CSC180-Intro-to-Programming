//
//  gebw.c
//  Lab 8
//
//  Created by Chenqi Li on 2018/11/8.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

int ge_bw(float *matrix, int rows, int cols, float *matrix_out);


int main(void) {
   float matrix[16] = {1000, 3, 5, 10, 0, -2, 1, 3, 0, 0, 11.98, 7.957};
   float matrix_out[1] = {1};
   int i = 0;
   int j = 0;
   int cols;
   int rows;
   
   
   ge_bw(matrix, 3, 4, matrix_out);
   
   //TEST final
   printf("matrix_out\n");
   for (i=0;i<3;i++) {
      for (j=0;j<4;j++) {
         printf("%8.3f ", matrix_out[i*4 + j]);
      }
      printf("\n");
   }
   printf("\n");
   
}


int ge_bw(float *matrix, int rows, int cols, float *matrix_out) {
   //Initialize *matrix_out, i
   int i = 0;
   int j = 0;
   float multiple = 0.0;
   int cnt = 1;
   int st = 0;
   int rowso = rows;
   int colso = cols;

   
   while (rows>1){
      //TEST initial
      printf("Before reduction\n");
      for (i=0;i<3;i++) {
         for (j=0;j<4;j++) {
            printf("%8.3f ", matrix[i*colso + j]);
         }
         printf("\n");
      }
      printf("\n");
      
      for (i=0;i<rows;i++) {
         for (j=0;j<cols;j++) {
            if (matrix[i*cols + i] != 0) {
               multiple = matrix[i*cols+i];
            }
            matrix[i*cols + j] = matrix[i*cols + j] / multiple;
         }
      }
      
      //TEST initial
      printf("Before reduction\n");
      for (i=0;i<3;i++) {
         for (j=0;j<4;j++) {
            printf("%8.3f ", matrix[i*colso + j]);
         }
         printf("\n");
      }
      printf("\n");
      
      
      //Make rest of column to 0
      for (i=0;i<rows-1;i++) {
         printf("i %d\n", i);
         if (matrix[i*colso + (rows-1)] != 0) {
            //matrix[(rows*cols)-1] is last element of columns
            //matrix[colso*(cols) - cnt] is last element of matrix
            multiple = - (matrix[i*colso + (rows-1)])/(matrix[colso*(cols) - cnt]);
            
            for (j=st;j<cols;j++) {
               printf(" %f\n", matrix[i*cols +j]);
               matrix[i*colso + j] += multiple*matrix[(rows-1)*colso + j];
            }
            
         }
      }
      
      

      
      //TEST initial
      printf("After reduction\n");
      for (i=0;i<4;i++) {
         for (j=0;j<4;j++) {
            printf("%8.3f ", matrix[i*colso + j]);
         }
         printf("\n");
      }
      printf("\n");
      
      
      //Restate row and column number and counter
      rows -= 1;
      cols -= 1;
      cnt += 1;
   }
   
   
   matrix_out = matrix;
   return 0;
}

//}


//printf("%8.3f \n", multiple*matrix[(rows-1)*cols + j]);
/*
//Set to matrix_out
for (i=st;i<rows;i++) {
   for (j=st;j<cols;j++) {
      matrix_out[(i+cnt)*cols + (j+cnt)] = matrix[i*cols + j];
   }
}
*/
