#include<iostream>
using namespace std;
int main(){
long long  n,q,sum=0,v,g;
cin>>n;


for(int j=1;j<=n;j++){
cin>>v;
  sum=sum+v;
    if(j==1){
        g=v;
    }
    if(v>g){
        g=v;
    }
}


cin>>q;
cout<<(g*n-sum)*q<<endl;
return 0;
}
