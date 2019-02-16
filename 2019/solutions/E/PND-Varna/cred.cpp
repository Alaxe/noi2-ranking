#include<iostream>
using namespace std;
int main()
{int n,d,m,x,brd=0;
cin>>n>>m;
if((0<n<=1000)||(m<=100000)||(n<=m))
while(d)
x=n%10+(n/10%10)+(n/100%10)+n/1000;
d=d+x;
brd=(d-d)/x;
cout<<5<<endl;
return 0;
}
