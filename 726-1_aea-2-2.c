#include <stdio.h>

int main()
{
 long int n = 0;
 long long int comp = 1;
 long int input = 0;
 long int i = 0;
 scanf ("%li", &n);
 for (i=1; i<=n; i++)
  {
   scanf ("%li", &input);
   comp *= input;
  };
 printf ("%lli", comp);
 return 0;
}
