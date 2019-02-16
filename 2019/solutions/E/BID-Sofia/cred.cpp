#include<iostream>
using namespace std;
int cif(int CH){
    int sbor=CH;
    while(CH>0){
        sbor=sbor+CH%10;
        CH=CH/10;
    }
    return sbor;
}
int main(){
    int n,m,br=0;
    cin>>n>>m;
    while(n<m){
        n=cif(n);
        br++;
    }
    cout<<br<<endl;
    return 0;
}
