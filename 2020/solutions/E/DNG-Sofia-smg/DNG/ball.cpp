#include<iostream>
using namespace std;
int main(){
    bool chasha_1=false;
    bool chasha_2=false;
    bool chasha_3=false;
    long long n,x;
    cin>>n>>x;
    if(x==0){
        if(n%6==0 || n%6==5)
            cout<<0;
        else{
            if(n%6==1 || n%6==4)
                cout<<1;
            else
                cout<<2;
        }
    }
    else{
        if(x==1){
            if(n%6==1 || n%6==2)
                cout<<0;
            else{
                if(n%6==0 || n%6==3)
                    cout<<1;
                else
                    cout<<2;
            }
        }
        else{
            if(n%6==3 || n%6==4)
                cout<<0;
            else{
                if(n%6==2 || n%6==5)
                    cout<<1;
                else
                    cout<<2;
            }
        }
    }
return 0;}
