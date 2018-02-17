#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,k,s=1,p;
    cin>>n>>k;
    for (i=0;i<n-1;i++) s*=10;
    p=s%k;
    if (s%k==0) p=k;
    cout<<s+k-p<<endl;
    return 0;
}
