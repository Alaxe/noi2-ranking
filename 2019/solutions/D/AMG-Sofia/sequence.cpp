#include<bits/stdc++.h>
using namespace std;
unsigned long long m,l,a,b,p;
int n,k,i,f;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>k;
i=n;
while(i>0){
a+=2;
if(a==2){
a--;
}
i--;
}
i=n;
m=0;
l=1;
while(i>0){
m+=l;
l+=2;
if(l==3){
l--;
}
i--;
}
i=0;
b=2;
p+=m;
while(i<k-1){
if(i%2==0){
p+=a;
}else{
p+=b;
b+=2;
}
i++;
}
cout<<p<<endl;
return 0;
}
