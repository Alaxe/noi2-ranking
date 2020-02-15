#include<bits/stdc++.h>
using namespace std;
int a[100]={0};
bool b[100]={0};
int main(){
    int n,s,s2;
    cin>>n>>s>>s2;
    s=s*s2;
    int x=0,m=0,z;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;){
        x=a[i];
        z=i;
        i++;
        while(a[i]<x&&i<n-1){
            b[i]=1;
            i++;
        }
        if(i<n-1)continue;
        i=z;
        for(int j=i;j<n;j++)b[i]=0;
        i++;
    }
    m=0;
    int c=0;
    for(int i=0;i<n;){
        x=a[i];
        i++;
        c=1;
        while(b[i]==1){
            i++;
            c++;
        }
        m+=min(a[i],x)*c;
    }
    cout<<m*s<<endl;
}
