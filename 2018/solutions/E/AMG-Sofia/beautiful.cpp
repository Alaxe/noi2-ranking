#include<iostream>
using namespace std;
int main(){
long long n,k,a,b=1,c;
cin>>n>>k;
for(a=0;a<n;a=a+1){
b=b*10;
}
c=b;
b=b/10;
for(a=0;a<c;a=a+1){
if(b%k==0){
cout<<b;
break;
}
b=b+1;
if(k>=c){
cout<<"NO";
break;
}
}

return 0;
}

