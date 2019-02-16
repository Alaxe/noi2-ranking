#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n,k;
  cin>>n>>k;
  if (k==1) cout<<(n-1)*(n-1)+n<<endl;
    if (k%2==0 and k>1) cout<<n*n+n+n+1+n<<endl;
    if (k%2!=0 and k>1 ) cout<<(n+1)*(n+1)-(n-1)+((k-3)/2*10)<<endl;
//cout<<n*n+n+((k-1)/2)


return 0;
}


