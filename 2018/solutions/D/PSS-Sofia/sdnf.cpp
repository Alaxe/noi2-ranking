#include<iostream>
using namespace std;
int main(){
long long n,b=0,c=0,s,a,counte=0,f=1,k=0;
cin>>n;
a=n;
while(n>1){
    c++;
    n=n-1;
    a=a*n;
}


while(a>1){
        b=b+a%10;
a=a/10;}
cout<<b;


return 0;}
