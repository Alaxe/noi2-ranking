#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n,m;
    long long res;
    cin>>n>>m;
    long long i1=floor(sqrt(n));
    long long i2=floor(sqrt(m));
    long long divisible1=floor(sqrt(n))*ceil(sqrt(n));
    long long divisible2=floor(sqrt(m))*ceil(sqrt(m));
    //cout<<divisible1<<" "<<divisible2<<endl;
    res=i2-i1;
    if(i1*i1==n){
        res--;
    }
    if(n<4){
        res=i2;
    }
    if(i2*i2==m){
        res--;
    }
    if(i1==i2){
        if(n<=divisible1 && m>=divisible1){
            res=1;
        }else{
            res=0;
        }
    }
    if(divisible2>m){
        res--;
    }
    cout<<res<<endl;
    return 0;
}

