#include<iostream>
using namespace std;
int main(){
long long M,K,a[200],i=0,SborNaChetniteChisla;
cin>>M>>K;
cin>>a[i];
while(SborNaChetniteChisla<K)
if(a[i]%2==0){
    SborNaChetniteChisla=SborNaChetniteChisla+a[i];
    i++;
        cin>>a[i];
    }else{
    cin>>a[i];
    i++;
}
    cout<<SborNaChetniteChisla;
return 0;
}
