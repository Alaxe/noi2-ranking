#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>susedi[100000];
bool visited[100000];
int d[100000];
int ans=2;
queue<int> output;
void dfs(int i,int depth)
{
    visited[i]=1;
    d[i]=depth;
    if(susedi[i].size()>ans)
    {
        ans=susedi[i].size();
    }
    for(int j=0; j<susedi[i].size(); j++)
    {
        if(visited[susedi[i][j]]==0)
        {
            dfs(susedi[i][j],depth+1);
        }
        else
        {
            if((depth-d[susedi[i][j]]+1)%2==1)
            {
                if(ans==2)
                {
                    ans=3;
                }
            }
            return;
        }
    }
}
int main()
{
    int n,k;
    int t;
    cin>>t;
    for(int br=0; br<t; br++)
    {
        ans=2;
        cin>>n;
        for(int i=0;i<n;i++){
            visited[i]=0;
            d[i]=0;
            susedi[i].clear();
        }
        for(int i=0; i<n; i++)
        {
            cin>>k;
            k--;
            susedi[i].push_back(k);
            susedi[k].push_back(i);
        }
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(i,0);
            }
        }
        output.push(ans);
    }
    while(!output.empty()){
        cout<<output.front()<<endl;
        output.pop();
    }
    return 0;
}
