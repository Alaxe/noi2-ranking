#include<bits/stdc++.h>

using namespace std;

int main()
{
    const int nmax=256;
    int n, w1, w2, sum, ans=0;
    int a[nmax];
    bool dp[nmax];
    bool used[nmax];
    vector<vector<int>> v[nmax];
    cin>>n>>w1>>w2;
    if(w1>w2) swap(w1, w2);
    for(int i=0; i<n; ++i) cin>>a[i];
    //cout<<w1<<endl;
    for(int i=0; i<n; ++i)
    {
        for(int j=w1; j>0; --j)
        {
            if(dp[j]==1)
            {
                dp[j+a[i]]=1;
                for(int k=0; k<v[j].size(); ++k)
                {
                    v[j+a[i]].push_back(v[j][k]);
                    v[j+a[i]][v[j+a[i]].size()-1].push_back(i);
                }
            }
        }
        dp[a[i]]=1;
        vector<int> d={i};
        v[a[i]].push_back(d);
    }
    /*for(int i=w1; i>0; --i) if(dp[i]==1)
    {
        ans=i;
        break;
    }*/
    for(int i=1; i<=w1; ++i)
    {
        for(int j=0; j<v[i].size(); ++j)
        {
            memset(used, 0, sizeof used);
            memset(dp, 0, sizeof(dp));
            sum=0;
            for(int k=0; k<v[i][j].size(); ++k)
            {
                //cout<<v[i][j][k]<<"+";
                used[v[i][j][k]]=1;
                sum+=a[v[i][j][k]];
            }
            //cout<<"FIR"<<sum<<endl;
            //cout<<","<<endl;
            //for(int f=0; f<n; ++f) cout<<used[f]<<" ";
            //cout<<endl;
            for(int i1=0; i1<n; ++i1)
            {
                if(!used[i1])
                {
                    //cout<<"i1="<<i1<<endl;
                    for(int j1=w2; j1>0; --j1)
                    {
                        if(dp[j1]==1) dp[j1+a[i1]]=1;
                        //cout<<j1+a[i1]<<endl;
                    }
                    dp[a[i1]]=1;
                }
            }
            //for(int f=1; f<=w2; f++) cout<<dp[f]<<" ";
            //cout<<endl;
            for(int i1=w2; i1>0; --i1)
            {
                if(dp[i1]==1)
                {
                    sum+=i1;
                    break;
                }
            }
            ans=max(ans, sum);
            //cout<<sum<<endl;
        }
        //cout<<endl;
    }
    //cout<<ans<<endl;
    if(ans==0)
    {
        memset(dp, 0, sizeof(dp));
        //cout<<w2<<endl;
        for(int i=0; i<n; ++i)
        {
            for(int j=w2; j>0; --j)
            {
                if(dp[j]==1) dp[j+a[i]]=1;
            }
            dp[a[i]]=1;
        }
        for(int i=w2; i>0; --i) if(dp[i]==1)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
4 10 8
7 4 4 6
*/
