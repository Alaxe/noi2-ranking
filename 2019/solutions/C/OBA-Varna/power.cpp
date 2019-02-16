#include<bits/stdc++.h>
using namespace std;
int m[44],k,n,i,a,t;
long long sum=1;

bool ivan (int a)
{
    int j=0,br=0;

    if (a==1 || a==0) return 0;

    while (a%2==0)
    {
        a=a/2;
        br++;
    }
    if (m[2]<br) m[2]=br;

    for (j=3;j<=a;j++)
    {
        br=0;
        while (a%j==0)
        {
            a=a/j;
            br++;
        }
        if (m[j]<br) m[j]=br;
    }

    return 0;
}

int main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>a;
        ivan (a);
    }

    for (i=2;i<=43;i++)
    {
        if (m[i]%k!=0) m[i]=(m[i]/k+1)*k/k;
    }

    for (i=2;i<=43;i++)
    {
        for (t=1;t<=m[i];t++)
        {
            sum=sum*i;
        }
    }

    cout<<sum<<endl;
}
