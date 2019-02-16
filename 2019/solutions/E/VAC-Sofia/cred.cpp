#include<iostream>
using namespace std;
int main () {
long long m,c1,c2,c3,c4,c5,c6,n;
cin>>n>>m;
c1=n/100000;
c3=(n%10000)/1000;
c2=(n%100000)/10000;
c4=(n%1000)/100;
c5=(n%100)/10;
c6=n%10;
for(n=1;n<=m;n=n+c1+c2+c3+c4+c5+c6)
cout<<n<<" ";
return 0;
}
