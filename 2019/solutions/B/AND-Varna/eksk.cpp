#include<bits/stdc++.h>
using namespace std;
int n, a, b, path[200002], val[200002], ind;
bool used[200002];
vector <int> v[200002];
int dfs(int curr)
{
    if(used[curr])return 0;
    if(curr == b)
    {
        path[ind]=b;
        ind++;
        return -1;
    }
    bool f = false;
    used[curr]=true;
    for(int i=0; i<v[curr].size(); i++)
    {
        int sum=dfs(v[curr][i]);
        if(sum == -1)
        {
            f=true;
            path[ind]=curr;
            ind++;
        }
        else val[curr]+=sum;
    }
    used[curr]=false;
    if(f)return -1;
    else return val[curr]+1;
}
int main()
{
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin>>a>>b;
    dfs(a);
    //for(int i=0;i<ind;i++)cout<<path[i]<<" "<<val[path[i]]<<"\n";
    int i=0,j=ind-1, suma=1, sumb=1, ans=0;
    while(i<j)
    {//cout<<suma<<" "<<sumb<<"\n";
        if(!used[i])
        {
            suma+=val[path[i]];
            used[i]=true;
        }
        if(!used[j])
        {
            sumb+=val[path[j]];
            used[j]=true;
        }
        ans=max(ans,min(suma, sumb));
        if(suma<=sumb)
        {
        	suma-=val[path[i]];
            suma++;
            i++;
        }
        else if(sumb<=suma)
        {
        	sumb-=val[path[j]];
            sumb++;
            j--;
        }
        ans=max(ans,min(suma,sumb));

    }
    if(ans==max(suma, sumb))ans--;
    cout<<ans+1<<"\n";
    return 0;
}
/*
8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8
*/
