#include<bits/stdc++.h>
#define MOD (1<<30)
using namespace std;
long long m[16384];
int main()
{
    ios_base::sync_with_stdio(0);
    long long a,b,p,q;
    cin>>a>>b>>p>>q;
    b-=a; a=0;
    for(int i=b;i<=b+p;i++) m[i]=1LL;
    for(int i=b-1;i>=p;i--) m[i]=(m[i+p-q]+m[i+p])%MOD;
    cout<<m[p]<<endl;
    return 0;
}
