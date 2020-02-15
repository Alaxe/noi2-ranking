#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
vector< pair<int,int> > al[100001];
pair<int,int> r[200000];
int roads[100][100];
int used[100000];
bool use[100000];
bool open[200000];
long long res;
bool bfs(int s,int f,int u)
{
    used[s]=u+1;
    queue<int>num;
    num.push(s);
    while(!num.empty())
    {
        int s1=num.front();
        int l=al[s1].size();
        for(int i=0; i<l; i++)
        {
            if(al[s1][i].first==f && al[s1][i].second!=u)
            {
                return 1;
            }
            if(used[ al[s1][i].first ]<u+1 && al[s1][i].second!=u)
            {
                used[ al[s1][i].first ]=u+1;
                num.push(al[s1][i].first);
            }
        }
        num.pop();
    }
    return 0;
}
long long bfs1(int x)
{
    int br=1;
    use[x]=1;
    queue<int>num;
    num.push(x);
    while(!num.empty())
    {
        int y=num.front();
        int l=al[y].size();
        for(int j=0; j<l; j++)
        {
            if(use[ al[y][j].first ]==0 && open[ al[y][j].second ]==0)
            {
                use[ al[y][j].first ]=1;
                num.push(al[y][j].first);
                br++;
            }
        }
        num.pop();
    }
    return br;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        al[a].push_back( make_pair(b,i) );
        al[b].push_back( make_pair(a,i) );
        r[i].first=a;
        r[i].second=b;
    }
    for(int i=0; i<m; i++)
    {
        if(bfs(r[i].first,r[i].second,i)==0)
        {
            open[i]=1;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(use[i]==0)
        {
            long long br1=bfs1(i);
            if(br1>2)
                res+=(br1*(br1-1))/2;
        }
    }
    cout<<res<<endl;
}
/**
5 6
1 2
2 3
3 1
2 4
2 5
4 5

9 11
1 2
1 3
3 4
2 4
4 5
5 6
5 7
6 7
7 8
7 9
8 9

OSOWIEC
THEN
AND AGAIN
ATTACK OF THE
DEAD
HUNDREN MEN
FACING THE
LEAD
ONCE AGAIN
A HUNDRED MEN
CHARGE AGAIN
DIE AGAIN
*/
