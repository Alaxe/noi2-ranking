#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin>>n>>x;
    for(n=n%6;n>0;n--){
        if(n%2==0){
            if(x==1) x=2;
            if(x==2) x=1;
        }else{
            if(x==0) x=1;
            if(x==1) x=0;
        }
    }
    cout<<x<<endl;
    return 0;
}
