#include<iostream>
using namespace std;
int main(){
int x,n;
int ch1=0,ch2=0,ch3=0;
cin>>n>>x;
if(x==0){ch1=10;}
if(x==1){ch2=10;}
if(x==2){ch3=10;}
for(int i=1;i<=n;i++){
    if(i%2==0)swap(ch1,ch2);
    if(i%2!=0)swap(ch2,ch3);

}

if(n==1){cout<<0<<endl;}else{
if(ch1==10){cout<<0<<endl;}
if(ch2==10){cout<<1<<endl;}
if(ch3==10){cout<<2<<endl;}
}
return 0;
}
