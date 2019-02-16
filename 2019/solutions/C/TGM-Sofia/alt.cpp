#include <iostream>
using namespace std;

long long k,ans=0,n,m;
void br(long long l, long long preden){
    l++;
    if(l==n){
        ans++;
        return;
    }
    if(preden+k<m){
        br(l,preden+k);
    }
    if(preden-k>0){
        br(l,preden-k);
    }
    return;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie();
    long long i;
    cin >> k >> m >> n;
    for(i=1;i<m;i++){
        br(0,i);
    }
    cout << ans << endl;
return 0;
}

