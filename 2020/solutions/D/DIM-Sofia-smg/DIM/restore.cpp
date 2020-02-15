#include<bits/stdc++.h>
using namespace std;
int a[100004];
pair<int,int>m[100004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int len=0;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            m[len].first=0;
        }else{
            m[len].first=len;
            int j=len;
            for(int h=len-a[i];h>0;h--){
                swap(m[j].first,m[j-1].first);
                j--;
            }
        }
        len++;
    }
    for(int b=0;b<n;++b){
        m[b].first=n-m[b].first-1;
        m[b].second=n-b-1;
    }
    sort(m,m+n);
    for(int b=0;b<n;++b){
            if(b!=0)cout<<" ";
        cout<<m[b].second+1;
    }
    cout<<"\n";
return 0;
}

