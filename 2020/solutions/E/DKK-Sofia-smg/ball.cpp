#include <iostream>
using namespace std;
int main(){
long long n,x,a;
cin>>n;
cin>>x;

for(a=0;a<=n;a++){
    if(a%2==1){
    if(x==0){
        x++;

        }
    if(x==1){
        x--;

    }
    if(x==2){
x=x;
    }
    }
    if(a%2==0){

    if(x==1){
        x++;

    }
    if(x==2){
        x--;

    }
        if(x==0){
x=x;

        }
    }

}
cout<<x;
}
