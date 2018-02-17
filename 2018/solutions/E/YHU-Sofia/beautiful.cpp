#include<iostream>
using namespace std;
int main(){
long long brcif,del,a,b=0,c=0;
cin>>brcif>>del;
for(a=1;b<brcif;a=a*10){
    b++;
    c=c+a*9;
}
for(a=a/10;a<=c;a++){
    if(a%del==0){
        cout<<a;
        break;
    }
}

if(a==c+1){
  cout<<"NO";
}
return 0;
}
