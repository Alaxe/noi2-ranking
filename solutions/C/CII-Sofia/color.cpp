#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n,t,maxr,r[100001],res;
int used[100001][10];
int stepeni[100001][10];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        for(int j=1; j<=n; j++)
        {
            maxr=0;
            cin>>r[j];
            stepeni[j][i]++;
            stepeni[r[j]][i]++;
        }
        for(int j=1;j<=n;j++)
            if(maxr<stepeni[j][i])maxr=stepeni[j][i];
        used[1][i]=1;
        int k=1,l=0;
        bool in=1;
        while(true)
        {
            //if(in)in=0;
            if(used[r[k]][i]!=0)
            {
                l=used[k][i]+1-used[r[k]][i];
                break;
            }
            used[r[k]][i]=used[k][i]+1;
            k=r[k];
            //cout<<k<<" ";
        }
        if(l%2==0)
            res=max(2,maxr);
        else
            res=max(3,maxr);
        cout<<res<<endl;
    }
    return 0;
}
/**
14
3 14 4 2 6 4 6 7 10 6 13 13 13 6 1
*/
