#include<iostream>
using namespace std;

long long w,n,a[100000],m,b[100000],k,res=0;

bool solve(long long x,long long y)
{
    long long p;
    
    for(p=1;p<k;p++)
    {
        if(a[x+p]!=b[y+p])return false;
        if(w==1 && (a[x+p]<=a[x+p-1] || b[y+p]<=b[y+p-1]))return false;
        if(w==2 && (a[x+p]!=a[x+p-1] || b[y+p]!=b[y+p-1]))return false;
    }
    return true;
}

int main()
{
    long long i,j;
    cin>>w>>k;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    cin>>m;
    for(i=0;i<m;i++)cin>>b[i];
    
    for(i=0;i<=n-k;i++)
    {
        for(j=0;j<=m-k;j++)
        {
            if(a[i]==b[j])
            {
                if(solve(i,j))
                {
                    res++;
                }
            }
        }
    }
    
    cout<<res<<endl;
    return 0;
}
