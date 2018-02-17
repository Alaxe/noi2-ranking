#include <iostream>
char A[40000]={1}; int len=1, i=2, j, cf, n, tr0;
int main () {
  for (std::cin >> n; i<=n; i++) { /// perform n!
    for (j=tr0; j<len; A[j++]=cf%10, cf/=10) cf+=A[j]*i;
    for ( ; cf; cf/=10) A[len++]=cf%10;
    while (A[tr0]==0) tr0++;
  }
  for (i=j=0; i<len; j+=A[i++]);   /// j = (sum of digits of n!)
  std::cout << j << '\n';
  return 0;
}
