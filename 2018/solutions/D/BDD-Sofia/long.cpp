#include<iostream>
using namespace std;
int main (){
    long long i,k,n,p;
    cin>>n>>k;
    long long chislo=1;
    for(i=1;i<n;i++){
        chislo=chislo*10;
    }
    p=chislo/k;
    if(chislo%k!=0){
        chislo=k*(p+1);
    }
    cout<<chislo;
return 0;
}
