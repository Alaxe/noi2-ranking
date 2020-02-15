#include<iostream>
#include<vector>
using namespace std;

long long n,m,res=0;
struct connection
{
    long long x,y;
};
vector<long long>conn[1000];
vector<connection>st;
bool used[1005];

bool dfs(long long s,long long curr,long long f, connection z)
{
    if(curr==f)
    {
        return true;
    }
    long long i,j;
    for(i=0;i<conn[curr].size();i++)
    {
        if(used[conn[curr][i]]==false && (min(curr,conn[curr][i])!=z.x || max(curr,conn[curr][i])!=z.y))
        {
            used[conn[curr][i]]=true;
            if(dfs(s,conn[curr][i],f,z)){used[conn[curr][i]]=false;return true;}
            used[conn[curr][i]]=false;
        }
    }
    return false;
}

int main()
{
    connection p;
    long long i,j,k,a,b;
    bool poss;
    cin>>n>>m;
    
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        conn[a].push_back(b);
        conn[b].push_back(a);
        p.x=min(a,b);
        p.y=max(a,b);
        st.push_back(p);
    }
    
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            poss=true;
            used[i]=true;
            for(k=0;k<m;k++)
            if(dfs(i,i,j,st[k])==false)
            {
                poss=false;
                break;
            };
            used[i]=false;
            if(poss==true)
            {
                res++;
            }
            poss=true;
        }
    }
    cout<<res<<endl;
}
