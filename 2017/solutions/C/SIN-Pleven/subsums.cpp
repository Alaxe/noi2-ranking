#include<iostream>
using namespace std;
int sums[200002],nums[1001],ans,n;
int main ()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>nums[i];
    }
    short x[n+1];
    for (int i=1;i<=n;i++) x[i]=0;
    x[n]=1;
    int y=1;
    while (y!=n)
    {
        int i=n;
        while (x[i]==1) {x[i]=0; i--;}
        x[i]=1;
        y=0;
        for (i=1;i<=n;i++) y+=x[i];
        int z=0;
        for (i=1;i<=n;i++) z+=nums[i]*x[i];
        sums[z+100001]=1;
    }
    for (int i=1;i<=200002;i++) ans+=sums[i];
    cout<<ans<<endl;
    return 0;
}
