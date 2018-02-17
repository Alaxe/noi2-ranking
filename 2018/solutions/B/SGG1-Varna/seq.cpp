#include <iostream>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[272]={0};
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) a[i]=1;
    for (int i=1;i<=m;i++)
    {
        for (int j=n;j>=i;j--)
        {
            a[j]+=a[j-i];
        }
    }
    if (m==n) cout<<a[n]+1<<endl;
    else if (m==1)cout<<a[1]<<endl;
    else cout<<a[n]<<endl;
    return 0;
}
