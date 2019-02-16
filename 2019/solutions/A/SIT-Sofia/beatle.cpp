#include<bits/stdc++.h>
using namespace std;
const long long maxN=100001;
const long long biggg=1000000023000;
pair<long long,pair<long long,long long > > vhod[maxN];
long long otg[maxN];
long long durvo[maxN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n=0,x=0,y=0,d=0,gogr=0,dogr=0,t=0,a=0;

cin>>n;
for(int i=0;i<n;i++){
    cin>>x>>y>>d;

    dogr=min(dogr,x);
    gogr=max(gogr,x+d);
vhod[i]={y,{x,x+d}};
}
sort(vhod,vhod+n);
for(int i=0;i<n;i++){
    x=vhod[i].second.first;
    y=vhod[i].second.second;
    d=min(durvo[x-1],durvo[y])+1;
    for(int j=x;j<y;j++){
        durvo[j]=d;
    }
}
cin>>t;
for(int i=0;i<t;i++){
    cin>>a;

    otg[i]=durvo[a];
}
for(int i=0;i<t;i++){
    cout<<otg[i]<<" ";
}
cout<<"\n";
return 0;
}
