#include<bits/stdc++.h>
using namespace std;
int b[100000],a[100000];
int n,br=0,ind=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    a[0]=n-b[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(b[j]<b[i])br++;
            else {
                if(a[j]==a[i]){
                    br++;
                }
            }
        }
        a[i]=n-(br+b[i]);
        br=0;
    }
    for(int i=0;i<n-1;i++)cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
    return 0;
}
