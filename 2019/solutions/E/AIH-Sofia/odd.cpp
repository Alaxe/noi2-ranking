#include<iostream>
using namespace std;
int main(){
long long del,a,b,i,brdel,brotg=0;
cin>>a>>b;
for(i=a;i<=b;i++){
    brdel=0;
    for(del=1;del<=i;del++){
        if(i%del==0){
            brdel++;
        }
    }
    if(brdel%2==1){
        brotg++;
    }
}
cout<<brotg;
return 0;
}
