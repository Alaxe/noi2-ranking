#include<bits/stdc++.h>

using namespace std;

const int nmax=64;
int n, w;
int a[nmax];
int h[nmax];
bool used[nmax];
vector<int>v, k;
int cnt, ans;

void recurse(int pos, int last, int g[])
{
    if(pos==k.size()+1)
    {
        cnt++;
        if(ans==cnt)
        {
            int r[nmax];
            for(int i=1; i<=k.size(); ++i) r[i]=g[i];
            for(int i=0; i<n; ++i)
            {
                cout<<r[h[a[i]]]<<" ";
            }
            cout<<endl;
            exit(0);
        }
        return;
    }
    for(int i=last+1; i<=w-(k.size()-pos); ++i)
    {
        g[pos]=i;
        recurse(pos+1, i, g);
    }
}

int main()
{
    int g[nmax];
    memset(used, 0, sizeof used);
    memset(h, 0, sizeof(h));
    cin>>n>>w;
    for(int i=0; i<n; ++i) cin>>a[i], used[a[i]]=1;
    for(int i=1; i<=w; ++i) if(used[i]==1) v.push_back(i);
    for(int i=0; i<v.size(); ++i) h[v[i]]=i+1, k.push_back(i+1);
    //for(int i=0; i<v.size(); ++i) cout<<v[i]<<" ";
    //cout<<endl;
    //for(int i=1; i<=26; ++i) cout<<h[i]<<" ";
    //cout<<endl;
    sort(h, h+n);
    recurse(1, 0, g);
    //cout<<cnt<<endl;
    ans=(cnt+1)/2;
    cnt=0;
    recurse(1, 0, g);
    return 0;
}
/*
4 26
4 6 6 4
10 30
1 2 3 4 5 6 7 8 9 10
*/
