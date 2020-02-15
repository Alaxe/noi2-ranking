#include<iostream>
#include<vector>
#include<deque>
#define MAXN 100005
using namespace std;
vector<int> v[MAXN];
int n;
bool used[MAXN];
deque<int>qu;
vector<int> par[MAXN];
deque<int> tryy(int bot, deque<int> tillnow)
{
    int a;
    if(tillnow.size()==0) tillnow.push_back(bot);
    a = tillnow.back();

    //cout<<a<<endl;
    int b;
    bool k=0;
    deque<int> ans;
    deque<int> tryst;
    for(int i=0; i<v[a].size(); i++)
    {
        b=v[a][i];
        if(b==bot)
        {
            if(ans.size()<tillnow.size()) ans = tillnow;
            //continue;
        }
        if(used[b])continue;
        k=0;
        for(int j=0; j<par[b].size(); j++)
        {
            if(par[b][j]==a)
            {
                k=1;
                break;
            }
        }
        for(int j=0; j<par[a].size(); j++)
        {
            if(par[a][j]==b)
            {
                k=1;
                break;
            }
        }
        if(k)continue;
        par[b].push_back(a);
        tillnow.push_back(b);
        tryst = tryy(bot, tillnow);
        if(ans.size()<tryst.size()) ans = tryst;
        tillnow.pop_back();
        par[b].pop_back();
    }
    return ans;
}

int main()
{
    int m;
    int a, b;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        if(v[i].size()<2)used[i]=1;
    }
    deque<int>ht;
    deque<int> anss;
    int br=0;
    int brr=0;
    for(int i=1; i<=n; i++)
    {
    	brr=0;
        if(used[i])continue;
        anss=tryy(i,ht);
        used[i]=1;
        brr++;
        if(anss.empty())continue;
        while(!anss.empty())
        {
            brr-=used[anss.back()]-1;
            used[anss.back()] = 1;
            anss.pop_back();
        }
        br = br + (brr*(brr-1))/2;
    }
    cout<<br<<endl;
}

/**
5 5
1 2
2 3
3 1
2 4
2 5



5 6
1 2
1 3
2 3
2 4
3 5
4 5


10 13
1 2
1 3
2 3
3 4
3 5
4 5
3 6
6 7
6 8
7 8
2 9
9 10
10 2



*/
