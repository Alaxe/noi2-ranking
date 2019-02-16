#include<iostream>
using namespace std;
int main(){
long long s=0,br=0,n,i,a,b;
cin>>a>>b;
n=a;
while(n<b){
for(i=1;true;i=i=i*10){
    if(n/i==0){
        i/=10;
        break;
    }
}
for(s=n;i>=1;i/=10){
    s+=(n/i);
    n-=((n/i)*i);
}
n=s;
s=0;
br++;
}
cout<<br;
return 0;
}

