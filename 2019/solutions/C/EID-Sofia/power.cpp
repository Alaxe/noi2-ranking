#include<bits/stdc++.h>
using namespace std;
int br_razd, br_pyti, mch=0, ch=1, n, k, a[10003];
int main() {
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mch=max(mch, a[i]);
    }
    for(int i=2; i<mch; i++){
        br_pyti=0;
        br_razd=1;
        while(br_razd!=0){
            br_razd=0;
            for(int j=0; j<n; j++){
                if(a[j]%i==0){
                    br_razd++;
                    a[j]=a[j]/i;
                }
            }
            if(br_razd!=0)br_pyti++;
        }
        if(br_pyti>0){
            for(int j=1; j<=((br_pyti/k)+(br_pyti%k>0?1:0)); j++){
                ch=ch*i;
            }
        }
    }
    cout<<ch<<endl;
    return 0;
}
