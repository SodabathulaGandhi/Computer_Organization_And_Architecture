#include <stdio.h>
#include <conio.h>
#include <time.h>
int fib(int n)
{
  double num1 = 0, num2 = 1, result;
  int i;
  
  for (i = 0; i < n; i++)
  {
    if (i <= 1)
      result = i;
    else
    {
      result = num1 + num2;
      num1 = num2;
      num2 = result;
    }
    printf("%f\n", result);
  }
  return 0;
}

int main()
{ int n;
    printf("Please give an input upto you want to print series : \n");
   scanf("%d", &n);
   //printf("Fibonacci Series is:\n");
    clock_t t;
    t = clock();
    fib(n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("Fibonacci series took %f seconds to execute \n", time_taken);
    return 0;
}
