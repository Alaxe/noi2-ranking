#include<iostream>
using namespace std;
int main (){
long long n;
long long faktoriel=1;
long long l=0,sbor=0;
long long i;
cin>>n;
if(n>0 && n<=10000){
    for(i=1;i<=n;i++){
        faktoriel=faktoriel*i;
    }

         for(int k=1;k<=faktoriel;k=k*10){
            l++;
         }

         long long cifri[l];
         for(int m=0;m<l;m++){
            cifri[m]=faktoriel%10;
            faktoriel=faktoriel/10;
         }
         for(int v=0;v<l;v++){
            sbor=sbor+cifri[v];
         }
         cout<<sbor;
}
return 0;
}
