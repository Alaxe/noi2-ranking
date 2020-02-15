#include <bits/stdc++.h>
using namespace std;
int n;
int a[131072];
void print(int k)
{
    cout<<k<<endl;
    return;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(a[1]>a[2]){cout<<a[1]-a[2]<<endl;return 0;}
    for(int i=2;i<=n;i++)
    {
        if(a[i]<a[i-1])
        {
            print(a[i-1]-a[i]);
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
