//
//  sort.c
//  Lab 8
//
//  Created by Chenqi Li on 2018/11/8.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

int bubbleSort(int *array, int size);


int main(void) {
   int array[8] = {1,2,100,7,37,87,1,32};
   int i = 1;
   
   for (i=0;i<8;i++) {
      printf("%d ", array[i]);
   }
   
   bubbleSort(array,8);
   for (i=0;i<8;i++) {
      printf("%d ", array[i]);
   }
   
}

int bubbleSort(int *array, int size) {
   int n = 0;
   int swapped = 0;
   int i = 1;
   int temp = 0;
   
   //Check for empty list
   if (size == 0){
      return -1;
   }
   
   //Check for number of elements
   n = size;
   
   //Swap
   swapped = 0;
   while (swapped==0) {
      i = 1;
      swapped = -1;
      for (i=1;i<n;i++) {
         printf("%d \n", i);
         if (array[i-1]>array[i]) {
            temp = array[i-1];
            array[i-1] = array[i];
            array[i] = temp;
            swapped = 0;
         }
      }
   }

   return 0;
}
