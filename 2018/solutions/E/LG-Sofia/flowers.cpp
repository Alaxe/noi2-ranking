#include<iostream>
using namespace std;
int main(){
    long long a,q,naiGolqmo=0,br=0;
    cin>>a;
    long long n[a];
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    cin>>q;
    for(int b=0;b<a;b++){
        if(n[b]>naiGolqmo){
            naiGolqmo=n[b];
        }
    }
    for(int c=0;c<a;c++){
        br=br+(naiGolqmo-n[c]);
    }
    cout<<br*q;

    return 0;
}
