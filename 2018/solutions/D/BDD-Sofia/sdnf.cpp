#include<iostream>
using namespace std;
int main (){
    long long n,i,k;
    cin>>n;
    for(i=1;n>0;n--){
        i=i*n;
    }
    for(k=0;i!=0;i=i/10){
        k=k+i%10;
    }
    cout<<k;


return 0;
}
