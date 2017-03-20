#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long  k,l,n,x[9999],y[999999],w,h,t,x1,y1;
long long  x_prim[99999999],y_prim[9999999];
long long  a[999999];
long long minn,minn1;
long long aa[9999999],bb[9999999],u=0;
long long minn_pr=9999999,minn_pr1=9999999;
vector<int>v;
int lice(int x,int y,int kk)
{
    long long ak=x-x_prim[kk];
    long bk=y-y_prim[kk];

    return ak*bk;
}
int ll=0,lll=0;
void search_(int x1,int y1)
{
    for(int kk=1; kk<=n; kk++)
    {
        for(int i=y[kk]; i<=y_prim[kk]; i++)
        {
            if(y1==x[kk] || y1==i)
            {
                lll=1;
                if(y1==x[kk] || y1==i)
                {
                    minn=abs(y1-y[kk]);
                }
            }

        }

        for(int j=x[kk]; j<=x_prim[kk]; j++)
        {
            if(x1==j || x1==y[kk])
            {
                ll=1;
                if(x1==x[kk])
                    minn1=abs(x1-x[kk]);
                if(x1==j)
                    minn1=abs(x1-x[kk]);
            }

        }

        if(ll+lll==2)
        {
            v.push_back(lice(x[kk],y[kk],kk));
            break;

            ll=0,lll=0;
        }

    }

}
int main()
{
    cin>>k>>l>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i]>>w>>h;
        x_prim[i]=x[i]+w;
        y_prim[i]=y[i]+h;

    }
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>x1>>y1;
        search_(x1,y1);

    }
    for(int i=1; i<=v.size(); i++)
    {
        cout<<v[i-1]<<endl;
    }
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

11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
1
9 3
*/
