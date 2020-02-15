#include<bits/stdc++.h>
using namespace std;

int  red[100002],n;

int malko(int k){
int l=0,r=n,mid;

while(l<r){
    mid=(r+l)/2;
    if(red[mid]<k)l=mid+1;
    else r=mid;
}

return l;
}

int golqmo(int k){
int l=0,r=n,mid;
k++;

while(l<r){
    mid=(r+l)/2;
    if(red[mid]<k)l=mid+1;
    else r=mid;
}

return l;
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

int m,otK,doK;
cin>>n;
for(int i=0;i<n;i++)cin>>red[i];
red[n]=1000000;
sort(red,red+n);

cin>>m;
for(int i=0;i<m;i++){
    cin>>otK>>doK;
    doK=golqmo(doK);
    otK=malko(otK);
    cout<<doK-otK<<endl;
}

return 0;
}
