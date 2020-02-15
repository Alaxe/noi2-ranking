#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
long long n,u,v,a[100],vVoda=0;
cin>>n>>u>>v;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n-3;i++){
    vVoda+=a[i]*u*v;
}
if(a[n-3]<a[n-1]){
    vVoda+=(2*u)*a[n-3]*v;
}else{
    vVoda+=(2*u)*a[n-1]*v;
}
cout<<vVoda;
return 0;
}
