#include<iostream>
using namespace std;
int main(){
long long puti,chkrai,i,A=0,B=1,C=2;
cin>>puti>>chkrai;
for(i=puti;i>0;i=i-1){
    if(i%2==0){
        A=A+B;
        B=A-B;
        A=A-B;
    }else{
        C=C+B;
        B=C-B;
        C=C-B;
        }
}
cout<<A;
return 0;
}
