#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#pragma optimize GCC ofast
using namespace std;
struct vertex
{
    vector<int> empl;
    //int anc=-1;
};
unsigned int n,k;
vertex V[5004];
unsigned int depth[5004];
int final_res=INT_MAX-2;
bool visited[5004];
int bfs(int st)
{
    queue<int> q1;
    queue<int> q2;
    int dpt=1;
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
        depth[i]=0;
    }
    q1.push(st);
    visited[st]=1;
    int v=1;
    unsigned int curr_res=0;
    while(!q1.empty() or !q2.empty())
    {
        if(!q1.empty())
        {
            depth[dpt]=q1.size();
            dpt++;
        }
        while(!q1.empty())
        {
            int curr=q1.front();
            for(int i=0; i<V[curr].empl.size(); i++)
            {
                if(!visited[V[curr].empl[i]])
                {
                    q2.push(V[curr].empl[i]);
                    visited[V[curr].empl[i]]=1;
                    v++;
                }
            }
            q1.pop();
        }
        if(!q2.empty())
        {
            depth[dpt]=q2.size();
            dpt++;
        }
        while(!q2.empty())
        {
            int curr=q2.front();
            for(int i=0; i<V[curr].empl.size(); i++)
            {
                if(!visited[V[curr].empl[i]])
                {
                    q1.push(V[curr].empl[i]);
                    v++;
                    visited[V[curr].empl[i]]=1;
                }
            }
            q2.pop();
        }
    }
    if(v!=n)
    {
        return INT_MAX-2;
    }
    int salaries_on_prev_row=0;
    for(int i=dpt-1; i>=1; i--)
    {
        curr_res+=salaries_on_prev_row+depth[i];
        salaries_on_prev_row+=depth[i];
    }
    return  curr_res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    int o,u;
    for(int i=0; i<n; i++)
    {
        cin>>o;
        for(int j=0; j<o; j++)
        {
            cin>>u;
            V[u-1].empl.push_back(i);
        }
    }
    for(int i=0; i<n; i++)
    {
        //cout<<i<<"->"<<bfs(i)<<endl;
        final_res=min(final_res,bfs(i));
    }
    cout<<final_res*k<<endl;
}
