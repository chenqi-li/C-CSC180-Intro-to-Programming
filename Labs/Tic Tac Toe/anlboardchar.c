//
//  anlboardchar.c
//  Lab 7
//
//  Created by Chenqi Li on 2018/10/31.
//  Copyright © 2018 Chenqi Li. All rights reserved.
//

#include <stdio.h>

int main(void) {
   char t[9] = {'X', 'X', 'O', 'O', 'X', 'X', 'O', 'X', 'O'};
   //printf("%c\n", t[4]);
   
   printf("%d\n", anlboard(t,9));
   /*
   if (t[0] != '-' && t[1] != '-' && t[2] != '-' && t[0] == t[1] && t[1] == t[2]) {
      if (t[0] == 'X') {
         printf("%d\n", 1);
      }
      else if (t[0] == 'O') {
         printf("%d\n", 2);
      }
    }
    else {
       printf("This is false!\n");
    }
    */
}


int anlboard(char *T, int sizeT) {
   int n_open = 0;
   int i = 0;
   //012
   if (T[0] != '-' && T[1] != '-' && T[2] != '-' && T[0] == T[1] && T[1] == T[2]) {
      if (T[0] == 'X') {
         return 1;
      }
      else if (T[0] == 'O') {
         return 2;
      }
   }
   //345
   else if (T[3] != '-' && T[4] != '-' && T[5] != '-' && T[3] == T[4] && T[4] == T[5]) {
      if (T[3] == 'X') {
         return 1;
      }
      else if (T[3] == 'O') {
         return 2;
      }
   }
   
   //678
   else if (T[6] != '-' && T[7] != '-' && T[8] != '-' && T[6] == T[7] && T[7] == T[8]) {
      if (T[6] == 'X') {
         return 1;
      }
      else if (T[6] == 'O') {
         return 2;
      }
   }
   //036
   else if (T[0] != '-' && T[3] != '-' && T[6] != '-' && T[0] == T[3] && T[3] == T[6]) {
      if (T[0] == 'X') {
         return 1;
      }
      else if (T[0] == 'O') {
         return 2;
      }
   }
   //147
   else if (T[1] != '-' && T[4] != '-' && T[7] != '-' && T[1] == T[4] && T[4] == T[7]) {
      if (T[1] == 'X') {
         return 1;
      }
      else if (T[1] == 'O') {
         return 2;
      }
   }
   //258
   else if (T[2] != '-' && T[5] != '-' && T[8] != '-' && T[2] == T[5] && T[5] == T[8]) {
      if (T[2] == 'X') {
         return 1;
      }
      else if (T[2] == 'O') {
         return 2;
      }
   }
   //048
   else if (T[0] != '-' && T[4] != '-' && T[8] != '-' && T[0] == T[4] && T[4] == T[8]) {
      if (T[0] == 'X') {
         return 1;
      }
      else if (T[0] == 'O') {
         return 2;
      }
   }
   //246
   else if (T[2] != '-' && T[4] != '-' && T[6] != '-' && T[2] == T[4] && T[4] == T[6]) {
      if (T[2] == 'X') {
         return 1;
      }
      else if (T[2] == 'O') {
         return 2;
      }
   }
   
    //Checks for number of open spaces
   for (i=0;i<sizeT;i++) {
      if (T[i] == '-') {
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
