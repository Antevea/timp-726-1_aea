#include <stdio.h>

int main()
{
 long int n = 0;
 long long int sum = 0;
 long int input = 0;
 long int i = 0;
 scanf ("%li", &n);
 for (i=0; i<n; i++)
  {
   scanf ("%li", &input);
   sum += input;
   input = 0;
  };
 printf ("%lli", sum);
 return 0;
}
