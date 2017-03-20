#include<iostream>
using namespace std;
int main ()
{int a,b,c,d,r=1,maxr=0,i,n;
cin>>n>>a>>b;
for(i=1;i<n;i++)
{
    cin>>c>>d;
    if((c<=a && d<=b) || (c<=b && d<=a))r++;
    if(r>=maxr)maxr=r;
    a=c;b=d;
}if(r>=maxr)maxr=r;
cout<<maxr<<endl;






return 0;
}
