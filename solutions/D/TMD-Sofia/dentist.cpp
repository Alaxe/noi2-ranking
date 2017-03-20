#include<iostream>
using namespace std;
int main(){
long long pr[10000],ch[10000],t=0,i=0,i2=0,n,br,m=0;
while(cin>>pr[i]>>ch[i]){
i++;
}
n=i;
for(i=0;i<721;i++){
for(i2=0;i2<n;i2++){
if(pr[i2]==i){
t=t+ch[i2];
br=pr[i2];
m++;
}
}
if(i>t){
t=i;
}
if(m==n){i=720;}
}
cout<<t-br+1<<endl;
return 0;
}
