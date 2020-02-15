#include<iostream>
using namespace std;
int main (){
long long n,sbor=1,stypki=1,m=1,br=0;
cin>>n;
if(n>9){
    for(;sbor<1000000000000000000;){
        m=m*10;
        sbor=sbor+m;
        for(long long a=10;a<=n;a++){
            if(a%sbor==0){
                br=br+1;
            }
        }
    }
    br=br+9;
}
else{
    for(long long g=1;g<=n;g++){
        br=br+1;
    }
}
cout<<br<<endl;
return 0;
}
