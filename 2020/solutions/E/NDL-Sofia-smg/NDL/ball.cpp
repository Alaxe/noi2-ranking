#include<iostream>
using namespace std;
int main(){
    long long n;
    short int x;
    cin>>n>>x;
    for(n=n; n>0; n--){
        if(n%2==0){
            if(x==1){
                x=2;
            }else{
                if(x==2)x=1;
            }
        }else{
            if(x==0){
                x=1;
            }else{
                if(x==1)x=0;
            }
        }
    }
    cout<<x;
    return 0;
}
