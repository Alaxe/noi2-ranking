#include<iostream>
using namespace std;
int k,m,n;
int ans=0;

void dfs (int currPl, int currVal)
{
    if(currPl == n-1)
    {
        ans++;
        return;
    }
    if(currVal <= k)
    {
        dfs(currPl + 1, currVal + k);
    }else
    {
        if(currVal+k >= m)
        {
            dfs(currPl + 1, currVal - k);
        }else
        {
            dfs(currPl + 1, currVal + k);
            dfs(currPl + 1, currVal - k);
        }
    }
}
int main()
{
    cin>>k>>m>>n;
    for(int i = 1 ; i < m ; i ++)
    {
        dfs(0, i);
    }
    cout<<ans;
}
