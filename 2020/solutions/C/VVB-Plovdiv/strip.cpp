#include<bits/stdc++.h>
using namespace std;
long long n,k,mn,mx,ans;
void rec(long long i, long long j)
{
 //cout<<i<<" "<<j<<endl;
 if(j==n||i==1) {ans++;return;}
 rec(i-1,j);
 rec(i,j+1);
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
 cin>>n>>k;
 if(n<3) cout<<1<<endl;
 else
 {
   mn=k;mx=k;
   rec(mn,mx);
 }
 cout<<ans<<endl;
 return 0;
}
