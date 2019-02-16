#include<iostream>
using namespace std;
int main()
{
long long n,br=0,m,p;
cin>>n>>m;
while(n<m)
{
p=n;br++;
while(p)
{
n=n+p%10;
p=p/10;
}
}
cout<<br<<endl;
return 0;
}
