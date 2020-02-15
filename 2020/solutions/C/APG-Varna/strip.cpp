#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long a[100]= {1,1};
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    if(k==1||k==n)
    {
        cout<<1<<endl;
        return 0;
    }
    if(k==2||k==n-1)
    {
        cout<<n-1<<endl;
        return 0;
    }
    for(int i=2; i<n; i++)
    {
        for(int j=i; j>=1; j--)
        {
            a[j]+=a[j-1];
        }
    }
    cout<<a[k-1]<<endl;
    return 0;
}
