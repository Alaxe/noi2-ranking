#include<iostream>
using namespace std;
int main(){
long long n,k,nn=1,i,j;
cin>>n>>k;
for(j=n;j!=1;j=j-1){
    nn=nn*10;
};
for(i=nn;i%k!=0&&i!=(nn*10);i++){};
if(i<nn*10){
cout<<i<<endl;
}else{
cout<<"NO"<<endl;
};
return 0;
}
