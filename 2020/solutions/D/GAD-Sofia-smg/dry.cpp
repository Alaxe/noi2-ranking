#include <bits/stdc++.h>
using namespace std;

int volume(int x,int y,int z,int b[100]);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,u,v,vol,a[100];
    cin>>n;
    cin>>u;
    cin>>v;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    vol = volume(n,u,v,a);
    cout<<vol<<endl;
    return 0;
}

int volume(int x,int y,int z,int b[100]){
    int o=0,maks;
    for (int i=0;i<x;i++){
        if (i==0){
            maks=b[i];
        }else{
            if (b[i]>maks){
                maks=b[i];
            }
        }
    }
    for (int i=0;i<x;i++){
        if (b[i]!=maks){
            o+=b[i]*y*z;

        }
        if (i!=0 && b[i-1]>b[i] && i!=x-1 && b[i-1]!=maks && b[i+1]!=maks){
            if (b[i]>=b[i+1]){
                o+=b[i-1]*x*z-b[i]*x*z;
            }
        }
        if (i!=0 && b[i+1]>b[i] && i!=x-1 && b[i+1]!=maks && b[i-1]!=maks){
            o+=b[i+1]*x*z-b[i]*x*z;
        }
    }
    return o;
}
