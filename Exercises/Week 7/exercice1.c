/* #include is akin to "import" in python: it gives you access to
 externally-defined functions that may be useful.
 Here will include the "standard i/o" facililities so we can
 use printf and (if necessary) scanf for i and o
 */
#include<stdio.h>

/* Function Prototypes
 You must declare the "prototypes" of your functions here:
 * return value
 * name
 * arg types
 */

int powi(int a, int b);
int powirec(int a, int b);

/* Function Definitions --- sea of functions
 Now we define our functions.
 The prototype must match the above.
 main() is a special case: you do not need to declare a prototype for main()
 */

int powi(int a, int b) {
   int accum = 0, i = 0; /* always assign default values */
   accum = 1;
   for(i=0; i<b; i=i+1){
      accum = accum*a;
   }
   return accum;
}
int powirec(int a,int b) {
   if (b==1) {
      return a;
   } else {
      return a*powirec(a,b-1);
   }
}
int main(void){
   int err = 0, i = 0, j = 0;
   int u = 0, v = 0;
   err = 0;
   for (i=0;i<100;i=i+1){
      for (j=0;j<100;j=j+1){
         u = powi(i,j);
         v = powi(i,j);
         if (u != v) {
            printf("ERR: %d^%d = %d %d\n",i,j,u,v);
            err=err+1; }
      } }
   printf("Total errors: %d\n",err);
   return 0; }
