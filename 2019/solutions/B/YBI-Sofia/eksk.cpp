#include<iostream>
#pragma optimize GCC ofast
#include<vector>
#include<queue>
using namespace std;
struct v
{
    vector<int>adj;
    int type=0;///0-idk, 1-debel, 2-spec,3-dolen
};
int n;
int r,b;
v graph[200000];
vector<int> debeli_v;
bool visited[200000];
bool find_b_r(int curr)
{
    //cout<<"in"<<curr;
    visited[curr]=1;
    if(curr==r)
    {
        return 1;
    }
    bool x=0;
    for(int i=0; i<graph[curr].adj.size(); i++)
    {
        if(!visited[graph[curr].adj[i]])
        {
            if(find_b_r(graph[curr].adj[i]))
            {
                //cout<<"mark"<<curr<<endl;
                debeli_v.push_back(curr);
                graph[curr].type=1;
                x=1;
            }
        }
    }
    return x;
}
int max_depth(int curr)
{
    int res=1;

    visited[curr]=1;
    for(int i=0;i<graph[curr].adj.size();i++)
    {
        if(!visited[graph[curr].adj[i]])
        {
            res=max(res,1+max_depth(graph[curr].adj[i]));
            //cout<<"c-"<<curr<<" "<<res<<endl;
        }
    }

    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int u,v;
    for(int i=0; i<n-1; i++)
    {
        cin>>u>>v;
        graph[u-1].adj.push_back(v-1);
        graph[v-1].adj.push_back(u-1);
    }
    cin>>b>>r;
    b--;
    r--;
    debeli_v.push_back(r);
    find_b_r(b);
    int last=r;
    int min_r=0,min_b=0;
    for(int i=0; i<debeli_v.size(); i++)
    {
        //cout<<debeli_v[i]<<" ";///ot r do b putq
        graph[debeli_v[i]].type=1;
    }
    graph[r].type=2;
    graph[b].type=2;
    if(graph[r].adj.size()!=1)
    {

        for(int i=0; i<graph[r].adj.size(); i++)
        {

            if(graph[graph[r].adj[i]].type!=1 and graph[graph[r].adj[i]].type!=2)
            {
                for(int j=0; j<n; j++)
                {

                    visited[j]=0;
                }
                visited[r]=1;

                //cout<<graph[r].adj[i];
                min_r=max(min_r,max_depth(graph[r].adj[i]));

            }
        }
    }
    if(graph[b].adj.size()!=1)
    {
        for(int i=0; i<graph[b].adj.size(); i++)
        {
            if(graph[graph[b].adj[i]].type!=1 and graph[graph[b].adj[i]].type!=2)
            {
                for(int j=0; j<n; j++)
                {
                    visited[j]=0;
                }
                visited[b]=1;
                //cout<<graph[b].adj[i];
                min_b=max(min_b,max_depth(graph[b].adj[i]));
            }
        }
    }
    int final_res=min(min_r,min_b);
    for(int j=0; j<n; j++)
    {
        visited[j]=0;
    }
    for(int i=0;i<debeli_v.size();i++)
    {
        visited[debeli_v[i]]=1;
    }
    int kolko_nadolu[n];
    for(int i=1;i<debeli_v.size()-1;i++)
    {
        kolko_nadolu[i]=max_depth(debeli_v[i])-1;
        //cout<<"kd"<<i<<" "<<kolko_nadolu[i]<<endl;
    }
    int ako_r_moje_da_stigne[n+1];
    int ako_b_moje_da_stigne[n+1];
    ako_b_moje_da_stigne[0]=0;
    ako_r_moje_da_stigne[debeli_v.size()-1]=0;
    for(int i=1;i<debeli_v.size()-1;i++)
    {
        ako_r_moje_da_stigne[i]=max(ako_r_moje_da_stigne[i-1],kolko_nadolu[i]+i);
        //cout<<debeli_v[i]<<"->"<<ako_r_moje_da_stigne[0]<<"b"<<kolko_nadolu[i]+i<<endl;
    }
    for(int i=debeli_v.size()-2;i>=1;i--)
    {
        ako_b_moje_da_stigne[i]=max(ako_b_moje_da_stigne[i+1],kolko_nadolu[i]+(int)debeli_v.size()-1-i);
       // cout<<debeli_v[i]<<"->"<<ako_b_moje_da_stigne[i]<<endl;
    }
    for(int i=0;i<debeli_v.size()-2;i++)
    {
        final_res=max(final_res, min( max( min_r, ako_r_moje_da_stigne[i]) , max(min_b , ako_b_moje_da_stigne[i+1]) ) );
    }
   // cout<<"Final:"<<final_res+1<<endl;
   cout<<final_res+1<<endl;
    return 0;
}


