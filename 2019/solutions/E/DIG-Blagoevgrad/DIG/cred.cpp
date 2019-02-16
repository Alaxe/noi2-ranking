#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,m,l=0;
cin>>n>>m;
for(int i=n;i<=m; i=i+i%10+i/10)

{
l=l+1;
}
cout<<l<<endl;

return 0;
}
