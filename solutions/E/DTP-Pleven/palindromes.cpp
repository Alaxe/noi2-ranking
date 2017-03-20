#include<iostream>
using namespace std;
int main()
{
 int n,i,j,s=0,k=0,y,p=0,m,h,o,d=0,maxd=0,b=0,w=0;
 cin>>n;
 for(i=n-1;i>=1;i--)
 for(j=n-1;j>=1;j--)
    {
    //if(i*j==9009){cout<<i<<" "<<j<<endl;break;}
    p=i*j;
    //if(p==9009)
    h=p;

    while(p>0)
    {
m=p%10;
k=k*10+m;
p=p/10;
    }
    o=k;k=0;
    if(o==h)d=o;
    //cout<<d<<endl;
    if(d>maxd){maxd=d;b=i;w=j;}
    }
cout<<min(b,w)<<" "<<max(b,w)<<endl<<maxd<<endl;
return 0;
}

