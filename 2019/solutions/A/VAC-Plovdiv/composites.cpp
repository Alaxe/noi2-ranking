#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+17;

void mainp()
{
    long long n;
    cin>>n;

    if(n<10) {cout<<0<<endl; return;}
    for(int i=210; i<420; i++) if((long long)(n+i)%210==2) {cout<<n+i<<endl; return;}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mainp();
    return 0;
}

