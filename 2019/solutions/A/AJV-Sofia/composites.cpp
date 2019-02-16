#include<iostream>
#include<vector>
using namespace std;
long long n;
bool er[3001];
vector<long long>prosti;
long long c(long long a){
    long long ans=0;
    while(a/10>0){
        ans++;
        a=a/10;
    }
    return ans;
}
bool isPrime(long long a){
    bool ans=1;
    for(long long i=2;i<=a/i;i++){
        if(a%i==0){
            ans=0;
            break;
        }
    }
    return ans;
}
int main(){
cin>>n;
for(long long i=3;i<3000;i+=2){
    if(er[i]==0){
        prosti.push_back(i);
        for(long long r=3;r*i<3000;r+=2){
            er[r*i]=1;
        }
    }
}
//cout<<prosti.size()
if(n>=1000000000000000){
    long long bla=n%6-2+n;
    if(bla<n)bla+=6;
    cout<<bla;
    return 0;
}
for(long long i=n+n%2;i<=(n+4000);i+=2){
        if(c(i)-c(n)>1){
            break;
        }
bool dali=1;
for(long long r=0;r<prosti.size();r++){
if(isPrime(prosti[r]*prosti[r]+i)==1){
dali=0;
break;
}
}
if(dali==1){
    cout<<i<<"\n";
    return 0;
}
}
cout<<0;
return 0;
}
