/* compile via gcc -pedantic */
/* Function declarations */

#include <stdio.h>

/* the prototype just needs the types of the return value and the
 * arguments, in addition to the function name; however, you may also
 * name the arguments here, like with npowe */

int square(int);
int gcd(int,int);
float npow(float base,int exp);

/* Sea of functions: you will define your functions here
 * all code, all variable declarations MUST be written within
 * functions; you may not declare variables nor code outside
 * of functions
 *
 * A function can have an invisible line drawn between the top part
 * which will have variable declarations (and assigment of default
 * values), and the bottom part where the code resides
 */
int square(int x){
   return x*x;
}


int gcd(int a,int b){
   int x = a;
   int y = b;
   while (1) { /* analogous to while True */
      if (x > y) {
         x=x-y;
      } else if (x < y) {
         y=y-x;
      } else {
         return x; }
   } }


float npow(float base,int exp){
   int i = 0;
   float accum = 1;
   for(i=0; i<exp; i=i+1) {
      accum = accum / base;
   }
   return accum;
}


int main(void) {
   /* var declarations: you must assign a default value */
   int v1 = 0, v2 = 0, exp = 0;
   float base = 0;
   int ans_gcd = 0;
   float ans_npow = 0;
   /* code */
   printf("Enter an integer: ");
   scanf("%d",&v1);
   printf("Enter an integer: ");
   scanf("%d",&v2);
   printf("Enter a float: ");
   scanf("%f",&base);
   while (1) {
      printf("Enter a postive integer: ");
      scanf("%d",&exp);
      if (exp > 0) {
         break;
      } else {
         printf("Error: you entered non-positive %d\n",exp);
         printf("Error: you entered non-positive %d\n",exp);
      }
   }
   
   ans_gcd=gcd(v1,v2);
   ans_npow=npow(base,exp);
   printf("gcd of %d and %d is %d\nnpow of %f and %d is %f\n\n",
          v1,v2,ans_gcd,base,exp,ans_npow);
   return 0; }
