#include <iostream>
#include <time.h>
#include <cstdio>
#define MAX 100
long double F[MAX];

//#define TIME_UTC
using namespace std;
long double fib(int y) {
  if((y==1)||(y==0)) {
      return(y);
  }
  else if(F[y]!=-1)
  {
      return F[y];
  }
  else {
      return(fib(y-1)+fib(y-2));
  }
}

int main() {
   int y , j=0;
   cout << "Enter the number of Fibonacci Series you want :  ";
   cin >> y;
   
    clock_t t;
    t = clock();
    for(int x=0;x<MAX;x++)
    {
        F[x]=-1;
    }

   cout << "\nFibonnaci Series : ";
   //fib(y);
   while(j < y) {
      F[j]=fib(j);
      cout << " " << F[j];
      
      j++;
   }
   
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
     printf("\nFibonacci series took %f seconds to execute \n",time_taken);

   return 0;
}
