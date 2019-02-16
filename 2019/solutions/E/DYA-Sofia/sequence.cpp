#include<iostream>
using namespace std;
int main(){
long long n,mqsto=1,dobavqne=2;
cin>>n;

if(n==1){
    cout<<"1";
    return 0;
}

for(long long i=1;i!=n;i++){
    mqsto=mqsto+dobavqne;
    dobavqne=dobavqne+2;
}

cout<<mqsto;


return 0;
}
