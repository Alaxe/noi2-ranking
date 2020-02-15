#include <iostream>
using namespace std;
int n,c[100000],m;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    cin>>m;
    int a,b,cnt[100001];
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        for(int j=0;j<n;j++)
        {
            if(c[j]>=a&&c[j]<=b)cnt[i]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<'\n';
    }
    return 0;
}
