#include<bits/stdc++.h>
using namespace std;

long long n,a[100000],i,j,b[100000],k;

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin>>n;
k=n;
for(i=0;i<n;i++){
    cin>>b[i];
}
for(i=0;i<n;i++){
    j=0;
    while(b[j]!=0){
        b[j]--;
        j++;
    }
    b[j]--;
    a[j]=k;
    k--;
}
cout<<a[0];
for(i=1;i<n;i++){
    cout<<" "<<a[i];
}
cout<<endl;

return 0;
}
