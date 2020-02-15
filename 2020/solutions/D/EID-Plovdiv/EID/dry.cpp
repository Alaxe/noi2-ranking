#include<bits/stdc++.h>
using namespace std;
int main()
{
long long u,v,a[101],n,g,obem=0,obem1=0,dv=0;
cin>>n;
cin>>u>>v;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
for(int i=0;i<n;i++)
{
for(int j=i+2;j<n;j++)
{//if(dv>0){i=dv;dv=0;j=i+2;}
g=j-1;if(obem1>obem)obem=obem1;
obem1=obem;cout<<obem<<endl;

 while(g>=0)
{
if(a[j]>a[g]){obem1=obem1+u*v*a[j];dv=j;g--;}
else {obem1=0;dv=0;g=0;}}
}}
/*if(obem==1)
{
for(int i=0;i<n-1;i++)
{
obem=obem+u*v*a[i];
}
}*/




cout<<obem<<endl;;
}
/*
5 1 1
2 4 8 5 7

5 1 1
9 1 1 1 9

*/
