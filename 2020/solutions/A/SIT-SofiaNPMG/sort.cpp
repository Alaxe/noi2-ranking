#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxN=100001,BIG=99999999999;
ll order[maxN];
vector<ll> problematic;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
ll n,ans=BIG,sum=0,res=0,ost=0;
cin>>n;
for(int i=0;i<n;i++){
    cin>>order[i];
    sum+=order[i];
}
res=sum/n;
ost=sum%n;
if(n==1){
    ans=0;
}
if(order[0]>order[1]){
    problematic.push_back(0);
    ans=min(ans,abs(order[1]-order[0]));
    order[0]=order[1];
}
if(order[n-1]<order[n-2]){
   problematic.push_back(n-1);
    ans=min(ans,abs(order[n-1]-order[n-2]));
    order[n-1]=order[n-2];
}
for(int i=1;i<n-1;i++){
   if(order[i]>=order[i-1] and order[i]<=order[i+1]){
     continue;
   }else{
       //cout<<i<<" ";
    problematic.push_back(i);
        if(order[i]<order[i-1]){
            ans=min(ans,abs(order[i]-order[i-1]));
            order[i]=order[i-1];
        }else{
            ans=min(ans,abs(order[i]-order[i+1]));
            order[i]=order[i+1];        }
   }
}

if(problematic.size()==0){
    ans=0;
    cout<<ans;
}else{
    if(problematic.size()==1){
        cout<<ans;
    }else{
        ans=0;
       for(int i=n-2;i>0;i--){
            if(order[i]>order[i+1]){
                ans+=abs(order[i]-order[i+1]);
                order[i]=order[i+1];
            }
       }
       cout<<ans;
    }
}
cout<<"\n";
return 0;
}
/*
5
2 6 4 3 2
5
2 6 6 7 7
*/
