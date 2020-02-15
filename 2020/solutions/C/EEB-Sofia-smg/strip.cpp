#include<bits/stdc++.h>
using namespace std;
int req(int x, int y, int &br, int &n){
    if(x>1 && y<n){
        for(int i=0; i<2; i++){
            if(i==0){
                req(x-1, y, br, n);
            }else{
                req(x, y+1, br, n);
            }
        }
    }else{
        br++;
    }
}
int main(){
ios::sync_with_stdio(false);
int n, k, x, y, br=0;
cin>>n>>k;
x=k;
y=k;
if(k==1 || k==n){
    cout<<1<<endl;
    return 0;
}else{
    req(x, y, br, n);
    cout<<br<<endl;
}
return 0;
}
