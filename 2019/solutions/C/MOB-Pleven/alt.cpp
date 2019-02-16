#include<iostream>
using namespace std;
unsigned long long d_opt[51][51];
long long k,m,n;
unsigned long long alt(int x,int y)
{
    if(d_opt[y][x]>0)return d_opt[y][x];
    if(x+k<m)d_opt[y][x]+=alt(x+k,y+1);
    if(x-k>0)d_opt[y][x]+=alt(x-k,y+1);
    return d_opt[y][x];
}
int main()
{
cin>>k>>m>>n;
unsigned long long counter=0;
for(int i=0;i<51;i++)d_opt[n-1][i]=1;
for(int i=1;i<m;i++)
{
    counter+=alt(i,0);
}
cout<<counter<<endl;
return 0;
}
///HELLO
