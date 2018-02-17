#include<iostream>
using namespace std;
int main(){
long long n,k,mini=1,ost,maxi,res,i;
cin>>n>>k;
if(n==1){
mini=1;
maxi=9;
}
else{
for(i=1;i<=n-1;i++){
mini=mini*10;
}
maxi=mini*10-1;
}
if(k<=maxi){
ost=mini%k;
if(ost==0)res=mini;
else{
res=mini+(k-ost);
}
cout<<res<<endl;
}
else{
cout<<"NO"<<endl;
}
return 0;
}
