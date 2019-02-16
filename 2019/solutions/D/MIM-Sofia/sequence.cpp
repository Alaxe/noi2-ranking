#include <bits/stdc++.h>
using namespace std;
int i1,i2,i;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k,xXx_count_xXx=0,maxim=1;
    cin>>n>>k;
    for(i=1;xXx_count_xXx!=k;){
        for(i1=1;i1<=maxim;i1++){
            if(i1==n){
                xXx_count_xXx++;
            }
            if(xXx_count_xXx==k){
                cout<<i;
                break;
            }
           /// cout<<i1<<" ";
            i++;
            if(i1==maxim){
                for(i2=maxim-1;i2>0;i2--){
                    if(i2==n){
                        xXx_count_xXx++;
                    }
                    if(xXx_count_xXx==k){
                        cout<<i;
                        break;
                    }
              ///      cout<<i2<<" ";
                    i++;
                }
            }
        }
        maxim++;
        i1=0;
    }
    return 0;
}
/// 1 3 5 7 9 11...
/// 1 1 2 1 1 2 3 2 1 1 2 3 4 3 2 1 1 2 3 4 5 4 3 2 1 1 2 3 4 5 6 5 4 3 2 1 1 2 3 4 5 6 7 6 5 4 3 2 1
