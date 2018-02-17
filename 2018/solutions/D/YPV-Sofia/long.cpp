#include<iostream>
using namespace std;
string pow10(long long a){
    string res;
    for(int i=0;i<a-1;i++) res+='0';
    return res;
}
int main(){
    long long n;
    long long k;
    cin>>n>>k;
    unsigned long long num=1;
    for(int i=0;i<n-1;i++){
        num*=10;
    }
    if(n>=30){
        cout<<1<<pow10(n)<<endl;
        return 0;
    }
    unsigned long long ost;
    ost=num%k;
    if(ost==0) cout<<num;
    else cout<<num+(k-ost);
    cout<<endl;
    return 0;
}
