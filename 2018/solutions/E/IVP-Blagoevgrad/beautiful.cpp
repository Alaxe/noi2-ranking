#include<bits/stdc++.h>
using namespace std;
int main(){
unsigned long long n,k,a,b,c;
cin>>n>>k;
a=1;
b=9;
c=n-1;
while(c!=0){a=a*10;
c=c-1;}
c=n;
while(c!=0){b=b*10+9;
c=c-1;}
while(a<=b){if(a%k==0){cout<<a<<endl;
return 0;}
a=a+1;}
cout<<"NO"<<endl;
return 0;
}
