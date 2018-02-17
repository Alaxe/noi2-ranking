#include<iostream>
using namespace std;
int main(){
    long long n,fakt=1,sum=0;
    cin>>n;
    for(int g=1;g<=n;g++){
        if(g%10==0){
            fakt=fakt*(g/10);
        }
        else if(g%5==0){
            fakt=fakt/2*(g/5);
        }
        else if(g%5!=0){
                fakt=fakt*g;
        }
    }
    ///cout<<fakt<<endl;
    while(fakt>0){
       sum=sum+(fakt%10);
       fakt=fakt/10;
    }
    cout<<sum;
return 0;
}
