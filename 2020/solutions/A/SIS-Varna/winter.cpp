#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000;
int n,m;
int used[MAXN];
vector<int> v[MAXN];
void read()
{
    int x,y;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
bool check001()
{
    for(int i=1; i<=n; i++)
    {
        if(v[i].size()!=1 && v[i].size()!=n-1) return false;
    }
    return true;
}
bool check100()
{
    if((n-m)==1) return true;
    return false;
}
int findr(int s, int t,int st)
{
    used[s]=1;
    for(int i=0; i<v[s].size(); i++)
    {
        if(v[s][i]==t && st>1) return 1;
    }
    for(int i=0; i<v[s].size(); i++)
    {
        if(!used[v[s][i]])
        {
            st++;
            return findr(v[s][i],t,st);
        }
    }
    return 0;
}
int main()
{
    int cnt=0;
    read();
    if(check001())
    {
        cout<<0<<endl;
        return 0;
    }
    if(check100())
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(v[j].size()>1)
            {
                if(findr(i,j,1))
                {
                    cnt++;
                }
                for(int i=0; i<=n; i++) used[i]=0;
            }
        }
    }
    cout<<cnt<<endl;
	return 0;
}
