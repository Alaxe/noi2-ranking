#include<bits/stdc++.h>
#define MAXN 50005
using namespace std;
vector<int>v[MAXN];
void deletee(int a, int b)
{
    for(int i=0; i<v[a].size(); i++)
    {
        if(v[a][i]==b)
        {
            swap(v[a][i],v[a][v[a].size()-1]);
            v[a].pop_back();
            return ;
        }
    }
}
vector<int> answers;
int dfs(int na)
{
    vector<int> ans;
    ans.push_back(na);
    int newna =0;
    while(1)
    {
        if(v[na].size()!=0)
        {
            deletee(v[na][0],na);
            newna=v[na][0];
            swap(v[na][0],v[na][v[na].size()-1]);
            v[na].pop_back();
            na=newna;
            ans.push_back(na);
        }
        else break;
    }
    answers.push_back(ans.size());
    for(int i=0; i<ans.size(); i++)
    {
        answers.push_back(ans[i]+1);
    }
    answers.push_back(-1);
    return 0;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int a, b;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    a=-1;
    for(int i=0; i<n; i++)
    {
        if(v[i].size()%2==1)a=i;
    }
    if(a==-1)a=0;
    dfs(a);
    int br=0;
    br++;
    for(int i=0; i<n; i++)
    {
        while(v[i].size()>0)
        {
            dfs(i);
            br++;
        }
    }
    cout<<br<<endl;
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i]==-1)
        {
            cout<<endl;
            continue;
        }
        cout<<answers[i]<<" ";
    }
}

/**

8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3


*/
