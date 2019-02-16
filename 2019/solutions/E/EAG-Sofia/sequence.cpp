#include<iostream>
using namespace std;
int main(){
long long n,p=1,poz=0;
cin>>n;
for(long long i=1;p<n;i+=2){
    poz+=i;
    p++;
}
poz+=n;
cout<<poz<<endl;
return 0;
}
