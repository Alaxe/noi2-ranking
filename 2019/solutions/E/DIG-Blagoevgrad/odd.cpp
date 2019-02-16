#include <bits/stdc++.h>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
int delitel=0;
int suma=0;

for(int r=a;r<=b;r++)
{
for(int l=2;l<=r;l++)
if(r%l==0)
{
break;
}
if(r!=2 and r!=3 and r%5!=0 and r%2!=0 )
{
suma=suma+1;
}

if(r==4)
{
    suma=suma+1;
}
if(r==4)
{
suma=suma+1;
}
}

cout<<suma/2<<endl;
return 0;
}
