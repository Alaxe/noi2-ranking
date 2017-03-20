#include <iostream>
using namespace std;
int main()
{
    int max1,max2,max3,n,m,s,d,c,l,o,max4,max5,max6;
cin>>n>>m;
cin>>s>>d;
cin>>c>>l;
if(c>=s+d&&c>=n+m)cout<<l;
else if(s>=c+l&&s>=n+m)cout<<d;
else if(n>=s+d&&n>=c+l)cout<<m;
else{
if(c>s&&c>n)
    {max1=c;max4=l;
if(s>n) {max2=s;max5=d;max3=n;max6=m;}
else {max3=s;max6=d;max2=n;max5=m;};}
else if(s>c&&s>n){max1=s;max4=d;
if(c>n) {max2=c;max5=l;max3=n;max6=m;}
else {max3=c;max6=l;max2=n;max5=m;};}
else if(n>s&&n>c){max1=n;max4=m;
if(s>c) {max2=s;max5=d;max3=c;max6=l;}
else {max3=s;max6=d;max2=c;max5=l;};}
o=(max6-(max1-max3))+max5+max4;
cout<<o<<endl;}
}
