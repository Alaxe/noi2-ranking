#include<iostream>
using namespace std;
int main(){
long long n,a=2,i,MqstoVRedicata=1;
cin>>n;
for(i=1;i<n;i=i+1){
    MqstoVRedicata=MqstoVRedicata+a;
    a=a+2;
}
cout<<MqstoVRedicata;
return 0;
}
