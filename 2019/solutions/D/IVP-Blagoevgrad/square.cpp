#include <bits/stdc++.h>
using namespace std;
long a[10001];
int main(){
long n,i,d,d2,x,nod,x2,e=1,c;
cin>>n;
for(i=0;i<n;i++)
{
    cin>>a[i];
}
if(n==1)
{
    d=sqrt(a[0]);
    if(sqrt(a[0])==(int)(sqrt(a[0])))cout<<d<<endl;
    else cout<<a[0]*a[0]<<endl;
}
else
{
d=a[0];
d2=a[1];
for(i=1;i<n;i++)
{
    d2=a[i];
    x2=d;
    while(d!=0)
    {
        x=d;
        d=d2%d;
        d2=x;
    }
    nod=x2*a[i]/d2;
    d=nod;

}
while(sqrt(c)!=ceil(sqrt(c)))
{
    c=nod*e;
    e=e+1;
}
cout<<sqrt(c)<<endl;
}
return 0;
}

