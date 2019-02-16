#include <iostream>
using namespace std;
int n,a[100001];
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}
void solve()
{
    int cnt1=0,cnt2=0,cnt3=0,k=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[i+1]&&a[i]!=a[n])cnt1++;
        if(a[i]==a[n]&&a[i]>a[i-1])cnt1++;
    }
    for(int j=1;j<=n;j++)
    {
        if(a[j]>a[j+1]&&a[j]!=a[n])cnt2++;
        if(a[j]==a[n]&&a[j]<a[j-1])cnt2++;
    }
    while(a[k]<a[k+1])
    {
        cnt3++;
        k++;
    }
    for(int l=k;l<=n;l++)
    {
        if(a[l]>a[l+1]&&a[l]!=a[n])cnt3++;
        if(a[l]==a[n]&&a[l]<a[l-1])cnt3++;
    }
    cout<<max(cnt1,max(cnt2,cnt3));
}
int main()
{
read();
solve();
return 0;
}
