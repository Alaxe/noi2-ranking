#include<bits/stdc++.h>
using namespace std;
long long  n,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    long long s=min(k-1,n-k);
    long long b=max(k-1,n-k);
    b=b+1;
    for(long long i=1; i<=s-1; i++)
        b=b*2;
    if(s==0)
        b=1;
    cout<<b<<endl;
    return 0;
}
