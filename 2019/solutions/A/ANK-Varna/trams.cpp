#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <int> v1[50002];
vector <int> v[50002];
vector <bool> blacklist[50002];
int ans[50002];
int rem[50002];
bool used[100002];
bool inuse[50002];
int ind=0;
int br=0;
void euler(int a)
{
    ans[ind]=a;
    ind++;
    for(int i=0; i<v[a].size(); i++)
    {
        if(blacklist[a] [i]==0)
        {
            rem[a]-=1;
            rem[v[a][i]]-=1;
            blacklist [a] [i]=1;
            blacklist [v[a] [i]] [v1[a] [i]]=1;
            euler(v[a] [i]);
            return;
        }

    }
    cout<<ind<<" ";
    for(int i=0; i<ind-1; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[ind-1]<<endl;
}
int main()
{
    int a,b,c,d;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        c=v[b].size()-1;
        d=v[a].size()-1;
        v1[a].push_back(c);
        v1[b].push_back(d);
        blacklist[a].push_back(0);
        blacklist[b].push_back(0);
    }
    for(int i=1; i<=n; i++)
    {
        rem[i]=v[i].size();
        if(rem[i]%2==1) br++;
    }
    if(br==0) {euler(1); return 0;}
    cout<<br/2<<endl;
    for(int i=1; i<=n; i++)
    {
        if(rem[i]%2==1) euler(i);
        ind=0;
    }

    return 0;
}

/*
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
