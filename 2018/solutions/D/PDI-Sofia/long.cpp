#include<iostream>
#include<cmath>
using namespace std;
int main(){
int n,k;
int long long ci=1;
cin>>n>>k;
ci=pow(10,n-1);
if(ci%10!=0) ci++;
for(ci;ci%k!=0;ci++){}
cout<<ci;
return 0;
}
