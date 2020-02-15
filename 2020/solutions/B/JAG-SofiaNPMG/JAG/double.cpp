#include <iostream>
using namespace std;
int main()
{
 int n, W1, W2, sum = 0;
 int A[201];
 cin >> n >> W1 >> W2;
 for ( int i = 0 ; i < n ; i++) {cin >> A[i]; sum+=A[i];}
 if (sum > W1+W2) cout << W1+W2;
 else cout << sum;
 return 0;
}
