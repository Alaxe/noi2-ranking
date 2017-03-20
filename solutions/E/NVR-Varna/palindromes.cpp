#include<iostream>
using namespace std;
int main ()
{int n,ch1,ch2,i,pl,maxpl,ed,des,st,h,pr=1;
cin>>n;
{if(ch1<n&&ch2<n)pr=ch1*ch2;
while(ch1<=n&&ch2<=n)
ed=pr%10;
des=pr/10%10;
st=pr/100%10;
h=pr/1000;
if(h==ed&&des==st)pl=pr;pr=1;
if(pl>maxpl)maxpl=pl;
}
cout<<ch1<<" "<<ch2<<" "<<maxpl<<endl;
return 0;
}
