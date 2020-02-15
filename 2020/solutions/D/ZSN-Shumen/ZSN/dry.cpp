#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    int n,u,v,h[100];
    cin>>n>>u>>v;
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        if(i==n-1)
        {
            cout<<sum<<endl;
            return 0;
        }
        int r1;
        int maxn=0,minn=12;
        for(int j=i+1;j<n;j++)
        {
            if(h[j]>maxn)
            {
                maxn=h[j];
                r1=j;
            }
            if(h[j]<minn)
            {
                minn=h[j];
            }
        }
        int sm=0;
        if(h[i]<minn)
        {
            sm=h[i]*u*v;
        }
        else
        {
            for(int j=i+1;j<r1;j++)
            {
                h[j]=0;
            }
            int g=(r1-i)*u,g1=min(maxn,h[i]);
            sm=g*v*g1;
        }
        sum+=sm;
    }
    cout<<sum<<endl;
    return 0;
}
