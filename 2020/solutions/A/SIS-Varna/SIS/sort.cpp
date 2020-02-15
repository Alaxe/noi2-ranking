#include<bits/stdc++.h>
using namespace std;
int n,a[100000],cnt=0;
void read()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
}
void solve()
{
    for(int i=2; i<=n; i++)
    {
        if(a[i]>a[i-1])
        {
            if(a[i]>a[i+1])
            {
                if(a[i+1]>=a[i-1])
                {
                    cnt+=(a[i]-a[i+1]);
                    a[i]=a[i+1];
                }
            }
        }
        else if(a[i]<a[i-1])
        {
            cnt+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
}
int main()
{
    read();
    solve();
    cout<<cnt<<endl;
    return 0;
}
