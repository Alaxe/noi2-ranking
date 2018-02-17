#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long m, s_all, ok, fl, x_n, y_n, n, t, s[12000], x[12000], y[12000], w[12000], h[12000], ans[12000], x_t[12000], y_t[12000];
int main()
{
    cin>>x_n>>y_n;
    long long s_big=x_n*y_n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i]>>w[i]>>h[i];
        s[i]=w[i]*h[i];
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if ( (x[j]>x[i] && x[j]<x[i]+w[i]) && (x[j]+w[j]>x[i] && x[j]+w[j]<x[i]+w[i]) &&
                    (y[j]>y[i] && y[j]<y[i]+h[i]) && (y[j]+h[j]>y[i] && y[j]+h[j]<y[i]+h[i]) )
            {
                s[i]-=s[j];
            }
            if ( (x[i]>x[j] && x[i]<x[j]+w[j]) && (x[i]+w[i]>x[j] && x[i]+w[i]<x[j]+w[j]) &&
                    (y[i]>y[j] && y[j]<y[j]+h[j]) && (y[i]+h[i]>y[j] && y[i]+h[i]<y[j]+h[j]) )
            {
                s[j]-=s[i];
            }
        }
    }

    for (int i=1; i<=n; i++)
        s_all+=s[i];

    cin>>t;
    for (int k=1; k<=t; k++)
    {
        m=11000*11002;
        ok=0;
        fl=0;
        cin>>x_t[k]>>y_t[k];
        for (int i=1; i<=n; i++)
        {
            if ( (x_t[k]>x[i] && x_t[k]<x[i]+w[i]) &&
                    (y_t[k]>y[i] && y_t[k]<y[i]+h[i]))
            {

                ok++;
                fl=i;
            }
            if (ok!=0)
            {
                m=min(m, s[fl]);
            }
        }
        if (ok==0) m=s_big-s_all;
        ans[k]=m;
    }
    for (int i=1; i<=t; i++)
        cout<<ans[i]<<endl;

    return 0;
}
/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3
*/
