#include<iostream>
using namespace std;
int main()
{
 int n,a,b,i,br=0,maxbr=0,p,j,c,d,maxa,maxb;
 cin>>n>>a>>b;
 for(i=1;i<=n-2;i++)
 {
    cin>>c>>d;
 if(c<=a && d<=b)
{
br++;
if(a>maxa)maxa=a;
if(b>maxb)maxb=b;
}
else
{
if(c<=maxa && d<=maxb)br++;
else if(br>maxbr){maxbr=br;br=0;}
}
a=c;
b=d;
 }if(br>maxbr){maxbr=br;br=0;}
cout<<maxbr<<endl;


return 0;
}
