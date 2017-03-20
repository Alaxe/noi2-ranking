#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
 int  A[1000],B[1000],raz[1000],i=0,j,n=0;
  while ( scanf ("%i %i",&A[i],&B[i]) == 2 ) {i++; n++;}

 for ( i=0; i<n-1; i++ )
  for ( j=i; j<n; j++ ) if (A[i]>A[j]) { swap(A[i],A[j]); swap(B[i],B[j]); }

 for (i=0; i<n; i++)
 {
    if (i==n-1) {cout << B[i]; break;}
  if (A[i]+B[i] <= A[i+1]) B[i+1]=B[i+1];
   else  B[i+1]=B[i+1]+(A[i]+B[i]-A[i+1]);
 }
 return 0;
}
