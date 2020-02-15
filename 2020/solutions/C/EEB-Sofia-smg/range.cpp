#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int a[100001];
int b[100001];
int p[100001][2];
int main(){
int n, m, s=-1;
cin>>n;
for(int i=0; i<n; i++){
    cin>>arr[i];
}
sort(arr, arr+n);
for(int i=0; i<arr[n-1]; i++){
    p[i][0]=-1;
    p[i][1]=-1;
}
p[arr[0]][0]=0;
p[arr[n-1]][1]=n-1;
for(int i=1; i<n; i++){
    if(arr[i]!=arr[i-1]){
        p[arr[i]][0]=i;
        p[arr[i-1]][1]=i-1;
    }
}
for(int i=1; i<=arr[n-1]; i++){
    if(p[i][1]!=-1){
        s=p[i][1];
    }
    p[i][1]=s;
}
s=-1;
for(int i=arr[n-1]; i>=0; i--){
    if(p[i][0]!=-1){
        s=p[i][0];
    }
    if(s==-1){
        p[i][0]=0;
    }else{
        p[i][0]=s;
    }
}
cin>>m;
for(int i=0; i<m; i++){
    cin>>a[i]>>b[i];
    if(a[i]>arr[n-1]){
        cout<<0<<endl;
    }
    if(a[i]<=arr[n-1]){
        if(b[i]>arr[n-1]){
            cout<<n-p[a[i]][0]<<endl;
        }else{
            cout<<p[b[i]][1]-p[a[i]][0]+1<<endl;
        }
    }
}
return 0;
}
