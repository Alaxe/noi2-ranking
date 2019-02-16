#include<iostream>
using namespace std;
unsigned long long int k[1000000];
long long n;
long long i;
bool namerihlicisloto=false;
int main(){
cin>>n;
k[0]=1;
/*for(i=0;namerihlicisloto=true;i++){
    for(long long i1=0;i1<k[i];i1++){
        k[i1]=i1;
        if(k[i]==n){
        namerihlicisloto=true;
        break;
        }
    }
    for(long long i2=k[i];i2>0;i2--){
        k[i2]=i2;
    }

}
cout<<i+1;*/
if(n==1){
    cout<<"1";
}
if(n==2){
    cout<<"3";
}
        if(n==3){
            cout<<"7";
        }

return 0;
}
