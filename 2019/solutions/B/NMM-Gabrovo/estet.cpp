#include<bits/stdc++.h>
using namespace std;

const int MAXN=100002;
int n, a[MAXN], up[MAXN], down[MAXN];

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
    }

    up[0]=1;
    for(int i=1; i<n; ++i)
    {
        int bestNext=0;
        for(int j=i-1; j>=0; --j)
        {
            if(a[i]>a[j] && up[j]>bestNext)
            {
                bestNext=up[j];
            }
        }
        up[i]=bestNext+1;
        //cout<<up[i]<<" ";
    }
    //cout<<endl;

    down[n-1]=1;
    for(int i=n-2; i>=0; --i)
    {
        int bestNext=0;
        for(int j=i+1; j<n; ++j)
        {
            if(a[i]>a[j] && down[j]>bestNext)
            {
                bestNext=down[j];
            }
        }
        down[i]=bestNext+1;
        //cout<<down[i]<<" ";
    }

    //cout<<endl;

    int bestSol=0;

    for(int i=0; i<n; ++i)
    {
        int sum=up[i]+down[i]-1;
        bestSol=max(bestSol, sum);
    }

    cout<<bestSol<<endl;

    return 0;
}
/*
10
3 6 5 2 8 7 8 3 2 6
*/
