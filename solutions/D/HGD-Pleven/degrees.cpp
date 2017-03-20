#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
long long n,br=0,c,p,a;
cin>>a;
p=a;
while(a>0)
{
    c=p%10;
    br++;
    p=p/10;
}
if(br==1) n=1;
if(br==2) n=2;
if(br==3) n=3;
if(br==5) n=4;
if(br==7) n=5;
if(br==9) n=6;
if(br==12) n=7;
if(br==15) n=8;
if(br==18) n=9;
cout<<n<<endl;
return 0;
}
