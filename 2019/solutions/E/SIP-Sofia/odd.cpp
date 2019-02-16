#include <iostream>
using namespace std;
int main(){
long long i,j,b,d=0;
long long mnb,mxb,crbv;
cin>>mnb>>mxb;
crbv=mxb-(mnb-1);
long long de[crbv];
b=0;
for(i=mnb;i<mxb+1;i++){
    d=0;
    for(j=2;j<i/2;j++){
        if(i%j==0){
            d++;
            cout<<j<<" ";
        }
    }
    cout<<endl;
    d++;
    de[b]=d;
    b++;
}
for(i=mnb;i<mxb+1;i++){
    cout<<i<<"/"<<de[i]<<endl;
}
return 0;
}
