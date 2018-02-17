#include <iostream>
using namespace std;

long long q=10,n,k,p;

int main (){
long long i;


    cin>>n>>k;

    for(i=1;i<n-1;i++){
        q*=10;
    }

    i=q;
    while(1){
        if(i%k==0) break;
        i++;
    }

    cout<<i;


 return 0;
}
