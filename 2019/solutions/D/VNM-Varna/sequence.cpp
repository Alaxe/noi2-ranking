#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    cin>>n>>k;
    long long r, m;
    r=n+k/2;
    m=(r-1)*(r-1);
    if(k%2) m=m+2*r-n;
    else m+=n;
    cout<<m<<endl;
    return 0;
}

