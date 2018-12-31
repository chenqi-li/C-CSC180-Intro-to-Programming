//
//  anlboard.c
//  anlboard.c
//
//  Created by Chenqi Li on 2018/10/31.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>


int main(void) {
   int t[9];
   t[0] = 2;
   t[1] = 1;
   t[2] = 1;
   t[3] = 1;
   t[4] = 2;
   t[5] = 2;
   t[6] = 1;
   t[7] = 2;
   t[8] = 2;
   
   printf("%d\n", anlboard(&t,9));
   /*
   if (t[0] != 0 && t[1] != 0 && t[2] != 0 && t[0] == t[1] && t[1] == t[2]) {
      printf("%d\n", t[0]);
   }
   else {
      printf("This is false!\n");
   }
   */
}

int anlboard(int *T, int sizeT) {
   int n_open = 0;
   int i = 0;
   //012
   if (T[0] != 0 && T[1] != 0 && T[2] != 0 && T[0] == T[1] && T[1] == T[2]){
      return T[0];
   }
   //345
   else if (T[3] != 0 && T[4] != 0 && T[5] != 0 && T[3] == T[4] && T[4] == T[5]) {
      return T[3];
   }
   //678
   else if (T[6] != 0 && T[7] != 0 && T[8] != 0 && T[6] == T[7] && T[7] == T[8]) {
      return T[6];
   }
   //036
   else if (T[0] != 0 && T[3] != 0 && T[6] != 0 && T[0] == T[3] && T[3] == T[6]) {
      return T[0];
   }
   //147
   else if (T[1] != 0 && T[4] != 0 && T[7] != 0 && T[1] == T[4] && T[4] == T[7]) {
      return T[1];
   }
   //258
   else if (T[2] != 0 && T[5] != 0 && T[8] != 0 && T[2] == T[5] && T[5] == T[8]) {
      return T[2];
   }
   //048
   else if (T[0] != 0 && T[4] != 0 && T[8] != 0 && T[0] == T[4] && T[4] == T[8]) {
      return T[0];
   }
   //246
   else if (T[2] != 0 && T[4] != 0 && T[6] != 0 && T[2] == T[4] && T[4] == T[6]) {
      return T[2];
   }

   //Checks for number of open spaces
   for (i=0;i<sizeT;i++) {
      if (T[i] == 0) {
         n_open = n_open + 1;
      }
   }
   //Check if it is a draw
   if (n_open == 0) {
      return 3;
   }
   else {
      return 0;
   }
}


