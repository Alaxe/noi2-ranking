#include<bits/stdc++.h>
using namespace std;
long long a[100002],b[100002];
long long n,m,maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(long long i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    maxi=a[n-1];
    long long j=0;
    for(long long i=1; i<=maxi; i++)
    {
        if(a[j]==i)
        {
            while(a[j]==i)
            {
                b[i]++;
                j++;
            }
        }
        b[i]=b[i]+b[i-1];
    }
    cin>>m;
    long long c1,c2,l,u,ans[100000];
    for(long long i=0;i<m;i++){
       cin>>c1>>c2;
        if(c1>maxi)l=n;
        if(c2>maxi)u=n;
        if(c1<=maxi)l=b[c1-1];
        if(c2<=maxi)u=b[c2];
        ans[i]=u-l;
    }
    for(long long i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20
/////
35
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
1
1 39
*/
