#include<iostream>
using namespace std;
int main(){
    int n,x,a=0,b=1,c=2;
    cin>>n>>x;
    n=n%6;
    for(;n!=0;n--){
        if(n%2==0){
            b=b+c;
            c=b-c;
            b=b-c;
        }
        if(n%2==1){
            a=a+b;
            b=a-b;
            a=a-b;
        }
    }
    if(x==a)cout<<0<<endl;
    if(x==b)cout<<1<<endl;
    if(x==c)cout<<2<<endl;
    return 0;
}
