#include<iostream>
using namespace std;
int main(){
    long long n,k,tyr=1;
    cin>>n>>k;
    while(n!=1){
        tyr*=10;
        n--;
    }
    if(k>=tyr*10){cout<<"NO"<<endl;return 0;}
    if(tyr%k!=0){tyr+=(k-tyr%k);}
    cout<<tyr<<endl;
return 0;
}
