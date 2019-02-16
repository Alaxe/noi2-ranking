#include<iostream>
using namespace std;
int main(){
long long a,b,i,x=1,brnamerenichisla=0;
cin>>a>>b;
for(i=a;i<=b;i=i+1){
         if(i==4){
            x=2;
        }
        if(i==9){
            x=3;
        }
        if(i==16){
            x=4;
        }
        if(i==25){
            x=5;
        }
        if(i==36){
            x=6;
        }
        if(i==49){
            x=7;
        }if(i==64){
            x=8;
        }
        if(i==81){
            x=9;
        }
        if(i==100){
            x=10;
        }
       while(x*x==i){
            brnamerenichisla=brnamerenichisla+1;
            x=x+1;
    }
}
cout<<brnamerenichisla;
return 0;
}
