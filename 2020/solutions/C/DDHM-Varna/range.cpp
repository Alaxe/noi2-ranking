#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+2;
int cnt[MAXN],n,m;
int pref[MAXN];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<MAXN;i++)
    {
        pref[i]=pref[i-1]+cnt[i];
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<pref[b]-pref[a-1]<<endl;
    }
return 0;
}
