#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,m,i,suma=0;
cin>>n>>m;

for (i=n;i<=m;i=i+(i%10)+(i/10))
{
    suma=suma+1;
}
cout<<suma<<endl;



return 0;
}
