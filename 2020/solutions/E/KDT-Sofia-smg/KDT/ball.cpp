#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,x;
    cin>>n;
    cin>>x;
    n=n%6;
    if(n==0){
        cout<<x;
        return 0;
    }
    for(int i=n;i>0;i--){
        if(i%2==1){
            if(x==0){
                x=1;
            }else{
                if(x==1){
                    x=0;
                }
            }
        }
        if(i%2==0){
            if(x==2){
                x=1;
            }else{
                if(x==1){
                    x=2;
                }
            }
        }
    }
    cout<<x;

    return 0;
}
