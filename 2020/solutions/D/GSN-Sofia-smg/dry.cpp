#include<bits/stdc++.h>
using namespace std;

long long n,u,v,i,a[101],maxi=0,sb,r=1;

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin>>n>>u>>v;
for(i=0;i<n;i++){
    cin>>a[i];
}
for(i=0;i<n-1;i++){
    if(maxi<a[i]){
        sb=sb+r*maxi;
        maxi=a[i];
        r=1;
    }else{
        r++;
    }
}
sb=sb+r*min(maxi,a[i]);
cout<<sb*(u*v)<<endl;

return 0;
}
