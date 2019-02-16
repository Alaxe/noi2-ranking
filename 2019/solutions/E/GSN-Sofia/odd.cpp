#include<iostream>
using namespace std;

long long koren(long long x){
    int i;
    for(i=0;i<x;i++){
        if(i*i>=x){
            return i;
            break;
        }
    }
}

int main(){

long long a,b,i,j,deliteli=0,br=0;
cin>>a>>b;
cout<<koren(b)-koren(a)<<endl;


return 0;
}
