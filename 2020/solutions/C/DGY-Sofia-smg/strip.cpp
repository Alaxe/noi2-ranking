#include<bits/stdc++.h>
using namespace std;
unsigned long long din[50][50];
int main(){
    for(int a=0;a<=50;a++){
        for(int b=0;b<=50;b++){
            if(a==0){
                din[0][b]=1;
            }
            if(b==0){
                din[a][0]=1;
            }
            if(a!=0 and b!=0){
                din[a][b]=din[a-1][b]+din[a][b-1];
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int br,mqsto;
    cin>>br>>mqsto;
    cout<<din[mqsto-1][br-mqsto]<<endl;
    return 0;
}
