#include<iostream>
using namespace std;
int main(){
long long n,i,maxi=-9,j,b,s=0,h,g,q;
cin>>n;
long long ch[n];
for(i=1;i<=n;i++){
cin>>ch[i];
}
cin>>q;
for(j=1;j<=n;j++){
b=ch[j];
if(b>maxi)maxi=b;
}
for(h=1;h<=n;h++){
g=ch[h];
if(g<maxi)s=s+(maxi-g);
}
cout<<q*s<<endl;
return 0;
}
