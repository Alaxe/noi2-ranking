#include<iostream>
using namespace std;
int main (){

long long n,m,i;
cin>>n>>m;

for(i=0;n<=m;i++){
    n=n+n/10+n%10;
}
cout<<i;

return 0;
}
