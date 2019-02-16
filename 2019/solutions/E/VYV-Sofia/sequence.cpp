#include<iostream>
using namespace std;
int main(){
int n,mqsto=0,redove=0;
cin>>n;
while(n>redove){
    redove++;
    if(n==1){
        cout<<n;
    }else{
    mqsto=n*(n-1)+1;
    }
}
if(n!=1){
cout<<mqsto;
}
return 0;
}
