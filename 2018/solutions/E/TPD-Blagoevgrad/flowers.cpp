#include  <bits/stdc++.h>

int a[1000];
using  namespace  std;

int main()
{
 int i=0;
 int n,q,br=0,max;
 unsigned long long g=0;

 cin>>n;
 for (int i=0;i<n;i++) cin>>a[i];
  max=a[0];
  cin>>q;
 for (int i=0;i<n;i++)
    if (max<a[i]) max=a[i];
 for (int i=0;i<n;i++) g+=max-a[i] ;

      cout<<g*q<<endl;
return 0;
}
