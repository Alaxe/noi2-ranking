#include <iostream>

using namespace std;
int br=0;
int main()
{int a[1000],d,i,ans,max=0,n,j,d1,d2;
cin>>n;
    for (i=1;i<=n;i++)
    cin>>a[i];
    for (i=1;i<=n;i++)
    if (max<a[i]) max=a[i];
    for (d=1;d<=max;d++)
    {for (ans=1;ans<=n;ans++)
    {
        for (j=ans+1;j<=n;j++)
        {if ((a[ans]+d)==a[j])
        br++;}

    }}
    for (i=1;i<=n;i++)
    {
        d1=a[i+1]-a[i];
        d2=a[i+2]-a[i+1];
        if (d1==d2) br++;

    }


    cout<<br<<endl;

    return 0;
}
