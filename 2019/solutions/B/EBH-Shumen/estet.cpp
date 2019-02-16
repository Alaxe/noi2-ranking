#include <iostream>
using namespace std;

const int maxN=100001;
int n,a[maxN],br1[maxN],br2[maxN],br3[maxN],br_1=-1,br_2=-1,br_3=-1;

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
    int c;
    for(int i=1;i<=n;i++)
    {
        c=a[i];
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]>c)
            {
                br1[i]++;
                c=a[j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(br1[i]>br_1)br_1=br1[i];
    }
    br_1++;
    for(int i=1;i<=n;i++)
    {
        c=a[i];
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]<c)
            {
                br2[i]++;
                c=a[j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(br2[i]>br_2)br_2=br2[i];
    }
    br_2++;
    cout<<max(br_1,br_2)<<endl;
}

int main()
{
    read();
    solve();


return 0;
}
