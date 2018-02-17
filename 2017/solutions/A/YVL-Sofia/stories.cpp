#include<iostream>
using namespace std;
int a[10000010];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long n, k;
long long output=0;
long long mul, add, mod;
    cin>>n>>k;
    cin>>a[0]>>mul>>add>>mod;
    long long seitwann=0;
    for(int i=1;i<n;i++){
        a[i]=(a[i-1]*mul+add)%mod;
        if(a[i]>=a[seitwann]){
            seitwann=i;
        }
        if(i-seitwann>=k){
            seitwann=i-k+1;
            for(int j=i-k+2;j<=i;j++){
                if(a[j]>=a[seitwann]){
                    seitwann=j;
                }
            }
        }
        output+=a[seitwann];
//        cout<<a[seitwann]<<"\n";
    }
    cout<<output+a[0]<<"\n";
    return 0;
}
