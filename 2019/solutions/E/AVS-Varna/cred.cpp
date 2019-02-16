#include<iostream>
using namespace std;
int main(){
int n,m,br=0,i,d,a,b;
cin>>n>>m;
if(n<m)br++;
while(n<m)
{i=n%10;d=n/10%10;a=n/100%10;b=n/1000;n=n+i+d+a+b;
if(n<m)br++;}
cout<<br<<endl;
return 0;
}
