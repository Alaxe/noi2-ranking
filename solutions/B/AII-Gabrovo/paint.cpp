# include<iostream>
# include<algorithm>
# include<vector>
using namespace std;

struct rect
{
    int x,y,x1,y1;
    int a,b;
    int nom;
};

rect r[11001];

bool operator<(rect a, rect b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int S[11001];
vector<rect> k[11001];

int vis[11001];

void dfs(int u)
{
    vis[u]=1;
    for(int i=0; i<k[u].size(); i++)
    {
        if(!vis[k[u][i].nom])
        {
            S[u]-=S[k[u][i].nom];
            dfs(k[u][i].nom);
        }
    }
}
int main()
{
    cin>>r[0].a>>r[0].b;
    r[0].x=0;
    r[0].y=0;
    r[0].x1=r[0].a;
    r[0].y1=r[0].b;
    r[0].nom=0;
    S[0]=r[0].a*r[0].b;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>r[i].x>>r[i].y>>r[i].a>>r[i].b;
        r[i].x1=r[i].x+r[i].a;
        r[i].y1=r[i].y+r[i].b;
        r[i].nom=i;
        S[i]=r[i].a*r[i].b;
        for(int j=0; j<i; j++)
        {
            if(r[j].x<=r[i].x && r[j].x1>=r[i].x1)
                if(r[j].y<=r[i].y && r[j].y1>=r[i].y1) k[j].push_back(r[i]);
        }
    }
    /*for(int i=0; i<=n; i++)
    {
        cout<<"i= "<<i<<endl;
        for(int j=0; j<k[i].size(); j++)
        {
            cout<<k[i][j].x<<" "<<k[i][j].y<<endl;
        }
        cout<<endl;
    }*/

    for(int i=0; i<=n; i++)
    {
        if(!vis[i])
        dfs(i);
    }

    sort(r,r+n+1);
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int p,q;
        cin>>p>>q;
        int last=0;
        for(int j=0; j<=n; j++)
        {
           // cout<<r[j].x<<" "<<r[j].y<<" "<<r[j].x1<<" "<<r[j].y1<<endl;
            if(r[j].x<=p && r[j].x1>=p)
                if(r[j].y<=q && r[j].y1>=q) last=j;
        }
        cout<<S[last]<<endl;
    }
}

/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3
*/
