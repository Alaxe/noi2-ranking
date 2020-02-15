#include<iostream>
using namespace std;
int main(){
long long n,x,nakraq,izvqrshih=0;
cin>>n>>x;
nakraq=x;
if(izvqrshih<=n){
    if(n%2==0){
        if(x==2){
            nakraq=nakraq-1;
        }else{
            if(x==1){
                nakraq=nakraq+1;
            }
        }
    }else{


            if(x==1){
            nakraq=nakraq-1;
        }else{
            if(x==0){
                nakraq=nakraq+1;
            }
        }
    }
}
cout<<nakraq;
return 0;
}
