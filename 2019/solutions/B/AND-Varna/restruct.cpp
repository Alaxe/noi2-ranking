#include<bits/stdc++.h>
using namespace std;
int n, k, away[5002][5002], q[5002], indb, inde, indec, par[5002], val[5002];
vector <int> v[5002];
bool used[5002];
void update (int ind)
{
    val[ind]++;
    if(!ind)return;
    update(par[ind]);
}
int deg(int curr, int target)
{
    //cout<<curr<<" "<<target<<"\n";
    if(used[curr])return 10000;
    if(curr==target)return 0;
    if(away[curr][target])return away[curr][target];
    int ans=10000;
    used[curr]=true;
    for(int i=0; i<v[curr].size(); i++)
    {
        if(ans>deg(v[curr][i], target)+1)ans = deg(v[curr][i], target)+1;
    }
    away[curr][target] = ans;
    used[curr]=false;
    return ans;
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        for(int j=0; j<a; j++)
        {
            int b;
            cin>>b;
            v[b].push_back(i);
        }
    }
    memset(away, 0, sizeof(away));
    int minimum=10000,mind, sum;
    for(int i=1; i<=n; i++)
    {
        sum = 0;
        for(int j=1; j<=n; j++)
        {
            sum+=deg(i, j);
        }
        if(sum<minimum)
        {
            minimum=sum;
            mind=i;
        }
    }
    used[mind]=true;
    par[mind]=0;
    int passednum=1;
    inde = 1;
    indb=1;
    for(int j=0; j<v[mind].size(); j++)
    {
        if(away[mind][v[mind][j]]==1)
        {
            q[inde] = v[mind][j];
            inde++;
            par[v[mind][j]]=mind;
            used[v[mind][j]]=true;
        }
    }
    indec=inde;
   	fill(val, val+n+1, true);
    while(passednum<n)
    {
        int mx=0, ind;
        if(indb==indec)indec=inde;
        for(int i=indb; i<indec; i++)
        {
            sum = 0;
            for(int j=0; j<v[q[i]].size(); j++)
            {
                if(used[v[q[i]][j]])continue;
                if(away[q[i]][v[q[i]][j]]==1)sum++;
            }
            if(mx<=sum)
            {
                mx=sum;
                ind=i;
            }
        }
        //cout<<q[ind]<<"\n";
        passednum++;

        update(par[q[ind]]);
        if(mx)
        {
            for(int j=0; j<v[q[ind]].size(); j++)
            {
                if(used[v[q[ind]][j]])continue;
                if(away[q[ind]][v[q[ind]][j]]==1)
                {
                    q[inde] = v[q[ind]][j];
                    inde++;
                    par[v[q[ind]][j]]=q[ind];
                    used[v[q[ind]][j]]=true;
                }
            }
        }
        if(ind!=indb)swap(q[ind], q[indb]);
        indb++;
    }
	//for(int i=1;i<=n;i++)cout<<i<<" "<<par[i]<<" "<<val[i]<<"\n";
    /*for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		cout<<i<<" "<<j<<" "<<away[i][j]<<"\n";
    	}
    }*/
    long long ans=0;
    for(int i=1;i<=n;i++)ans+=val[i];
    cout<<ans*k<<"\n";
    return 0;
}
/*
4 100
1 4
3 1 3 4
2 1 2
1 3
*/
