#include <iostream>
#include<cmath>
using namespace std;
int main ()
{
long long n,m,brd=0,brn=0,d;
cin>>n>>m;

d=ceil(sqrt(n));

for(int i=d;i*i<=m;i++)brn++;

cout<<brn<<endl;




}

