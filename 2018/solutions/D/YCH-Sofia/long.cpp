#include<iostream>
using namespace std;
int main(){
    long long n,k,m=1;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        m=m*10;
    }
    for(long long i=0;i<999999999999999999;i++){
        if((m+i)%k==0){
            cout<<m+i;
            return 0;
        }
    }
}
