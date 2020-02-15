#include <bits/stdc++.h>
using namespace std;
long long a[100001];
long long b[100001][3];
int main(){
long long n,m,i,i2,u,u2;
cin>>n;
for(i=0;i<n;i++)
{
    cin>>a[i];
}
cin>>m;
for(i2=0;i2<m;i2++)
{
    for(u=0;u<2;u++)
    {
        cin>>b[i2][u];
    }
}
sort(a,a+n);
for(i=0;i<m;i++)
{
    i2=n/2;
    u2=n/2;
    if((a[0]>b[i][1])or(a[n-1]<b[i][0]))cout<<0<<endl;
    else
    {
        if(a[i2]>b[i][0])
        {
            while(a[i2]>b[i][0])
            {
                i2=i2/2;
            }
            while(a[i2]<b[i][0])
            {
                i2=i2+1;
            }
        }
        else if(a[0]>b[i][0])i2=0;
        else
        {
            while(a[i2]<b[i][0])
            {
                i2=i2+(n-i2-1)/2;
            }
            while(a[i2]>b[i][0])
            {
                i2=i2-1;
            }
            if(a[i2]!=b[i][0])i2=i2+1;
        }
        if(a[u2]>b[i][1])
        {
            while(a[u2]>b[i][1])
            {
                u2=u2/2;
            }
            while(a[u2]<b[i][1])
            {
                u2=u2+1;
            }
            if(a[u2]!=b[i][1])u2=u2-1;
        }
        else if(a[n-1]<b[i][1])u2=n-1;
        else
        {
            while(a[u2]<b[i][1])
            {
                u2=u2+(n-u2)/2;
            }
            while(a[u2]>b[i][1])
            {
                u2=u2-1;
            }
        }
        cout<<u2-i2+1<<endl;
    }
}
return 0;
}
