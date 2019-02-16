# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;


struct desk
{
    int x,d;
    int nom;
    desk(int x, int d, int nom)
    {
        this->x=x;
        this->d=d;
        this->nom=nom;
    }
};
vector<desk> v[100001];
int n;
int maxy=0;
int dp[100001];

int BS(double x,int y)
{
    int l=0,r=v[y].size();
    while(l!=r)
    {
        int mid=(l+r)/2;
        if(v[y][mid].x<=x && x<=v[y][mid].x+v[y][mid].d) return mid;
        else if(v[y][mid].x>x) r=mid;
            else if(v[y][mid].x<=x && x>v[y][mid].x+v[y][mid].d) l=mid+1;
    }
    return -1;
}

int solve(double x, int y, int br)
{
    if(y==0) return br;

    int i=BS(x,y);
    if(i==-1) return solve(x,y-1,br);
    else
    {
        int c1,c2;
        if(v[y][i].x<=x && x<=v[y][i].x+v[y][i].d)
        {
            if(dp[v[y][i].nom]) return dp[v[y][i].nom]+br;
            c1=solve(v[y][i].x-0.5,y-1,br+1);
            c2=solve(v[y][i].x+v[y][i].d+0.5,y-1,br+1);
            if(!dp[v[y][i].nom]) dp[v[y][i].nom]=min(c1,c2)-br;
        }
        return min(c1,c2);
    }
}
struct inp
{
    int x,y,d;
};
inp input[100001];
bool operator<(inp a, inp b)
{
    return a.x<b.x;
}
int main()
{

    ios::sync_with_stdio();
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i].x>>input[i].y>>input[i].d;
        maxy=max(maxy,input[i].y);
    }
    sort(input,input+n);
    for(int i=0; i<n; i++)
    {
   //     cout<<input[i].x<<" "<<input[i].y<<" "<<input[i].d<<endl;
        v[input[i].y].push_back(desk(input[i].x,input[i].d,i+1));
    }
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        double x;
        cin>>x;
        cout<<solve(x+0.5,maxy,0)<<" ";
    }
    cout<<endl;
    return 0;
}
