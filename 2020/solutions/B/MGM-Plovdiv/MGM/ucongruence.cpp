#include <bits/stdc++.h>
using namespace std;
long long n, u, ans=1;
int a[1000000], b[1000000], c[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>u;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }

    sort(b, b+n);

    int j=1;
    c[0]=b[0];

    for(int i=1; i<n; i++)
    {
        if(b[i]!=b[i-1])
        {
            c[j]=b[i];
            j++;
        }
    }

    for(int i=1; i<=j; i++)
    {
        ans*=(u-i+1);
        ans/=i;
    }

    if(ans%2==1)
        ans++;
    ans/=2;

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    cout<<endl;
    return 0;
}

