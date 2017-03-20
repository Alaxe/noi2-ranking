#include<iostream>
using namespace std;
int main (){
long long n,a[100000],b[100000],BroiNaChislataVRedica=0;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
}
for(int j=0;j<n;j++){
    if(a[j]*b[j]>=a[j+1]*b[j+1]){
      BroiNaChislataVRedica++;
    }

}
cout<<BroiNaChislataVRedica;

return 0;
}
