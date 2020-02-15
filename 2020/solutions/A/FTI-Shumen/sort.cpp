#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
long long a[MAXN],ans,n;
void print(int x)
{
    cout<<x<<endl;
    exit(0);
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    if(n==1)print(0);
    if(a[1]>a[2])print(a[1]-a[2]);
    for(int i=2;i<=n;i++)
    {
        if(a[i]<a[i-1])
        {
            print(a[i-1]-a[i]);
        }
    }
    print(0);
    return 0;
}
