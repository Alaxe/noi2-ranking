#include<iostream>
using namespace std;
int main() {
    long long n,k,i,a=1,KopieNaK,KopieNaN,ost;
    bool vyzmojno=true;
    cin>>n>>k;
    KopieNaK=k;
    for(i=0;KopieNaK!=0;){
        KopieNaK=KopieNaK/10;
        i++;
    }
    if(i>n){
        vyzmojno=false;
    }
    if(vyzmojno==true){
        for(KopieNaN=n;KopieNaN>1;KopieNaN--){
            a=a*10;
        }
        ost=a%k;
        if(ost!=0){
            ost=k-ost;
        }
        a=a+ost;
        cout<<a;
    }else{
    cout<<"NO";
    }
return 0;
}
