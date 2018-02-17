#include<iostream>
using namespace std;
int main ()
{int n,a,b,a2,b2,a3,b3,bra=0,brb=0,br=0;
while((bra+brb)<=n)
cin>>n;
cin>>a;bra++;
cin>>b;brb++;
{if((a2<a&&b2<b)||(a2<a&&b2==b)||(a2==a&&b2<b)||(a2==a&&b2==b)||(a2==b&&b2==a))br++;
else if((a2>a&&b2==b)||(a2==a&&b2>b)||(a2>a&&b2>b))br=0; a=a2; b=b2; a2=a3; b2=b3;
}
cout<<br<<endl;
return 0;
}
