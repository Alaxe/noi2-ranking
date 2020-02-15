#include<bits/stdc++.h>
#define nl '\n'
using namespace std;

const int MAXN=1e5+69;

int n;
int arr[MAXN];

int findL(int v){
    int l=0;
    int r=n-1;
    if(arr[r]<v)return -1;
    if(arr[l]>=v)return l;
    while(l+1<r){
        int m=(l+r)/2;
        if(arr[m]>=v){
            r=m;
        }else{
            l=m;
        }
    }
    return r;
}

int findR(int v){
    int l=0;
    int r=n-1;
    if(arr[r]<=v)return n;
    if(arr[l]>v)return l;
    while(l+1<r){
        int m=(l+r)/2;
        if(arr[m]>v){
            r=m;
        }else{
            l=m;
        }
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr, arr+n);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a, b;
        cin>>a>>b;
        int l=findL(a);
        int r=findR(b);
        if(l==-1||r==-1){
            cout<<0<<nl;
            continue;
        }
        cout<<r-l<<nl;
    }
}
