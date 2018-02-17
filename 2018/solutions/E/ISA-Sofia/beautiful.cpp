#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n,k,gledano;
    bool NO=true;
    cin>>n>>k;
    gledano=pow(10,n-1);
    while(gledano<pow(10,n) && NO){
        if(gledano%k==0){
            NO=false;
            cout<<gledano;
        }
        gledano++;
    }
    if(NO){
        cout<<"NO";
    }
    return 0;
}
