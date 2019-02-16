#include<bits/stdc++.h>
using namespace std;
long long n,k,tek=0,i=0,dil=0;
string seq;
int main(){
cin>>n>>k;
do{
i++;
if(n<=i-1)tek=tek+2;
if(n==i)tek++;
dil=dil+(i-1)*2+1;
}
while(tek<k);
if(i==n)cout<<dil-(i-1)<<endl;
if(i>n){
if(tek-k==0){
    cout<<dil-(n-1)<<endl;
}
if(tek-k==1){
    cout<<dil-i-(i-n-1)<<endl;
}
}
return 0;
}

