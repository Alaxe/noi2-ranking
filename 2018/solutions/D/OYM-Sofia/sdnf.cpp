#include<iostream>
using namespace std;
int main(){
long long a,faktoriel=1;
cin>>a;
for(int i=2;i<=a;i++){
    faktoriel*=i;
}
long long sbor=0;
while(faktoriel>0){
    sbor+=faktoriel%10;
    faktoriel/=10;
}
cout<<sbor;
return 0;
}



