#include<bits/stdc++.h>
#define maxn int(3*1e5+5)
#define endl "\n"
using namespace std;
struct plank
{
    int x,y,len;
    plank(){};
    plank(int _x,int _y,int _len)
    {
        x=_x; y=_y; len=_len;
    }
    bool operator< (const plank &p)const
    {
        if(y==p.y)return x<p.x;
        return y<p.y;
    }
};

int n;
vector<plank>v;

void read()
{
    int i,x,y,d;
    v.push_back(plank(0,0,maxn));

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x>>y>>d;
        v.push_back(plank(x,y,d));
    }
    sort(v.begin(),v.end());
}

int ans[maxn];
int find_ans(int m,int x)
{
    int j;
    for(j=m;j>=0;j--)
    {
        plank t=v[j];
        if(t.x<=x&&t.x+t.len>x)
            return ans[j]+1;
    }
}

void prepare()
{
    ans[0]=0;
    int i,j,sz;
    sz=v.size();
    for(i=1;i<sz;i++)
    {
        plank p=v[i];
        ans[i]=min(find_ans(i-1,p.x-1),find_ans(i-1,p.x+p.len));
    }
}

void print_ans()
{
    vector<int>answer;
    int m,i,X;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>X;
        answer.push_back(find_ans(n,X)-1);
    }
    for(i=0;i<m;i++)
        cout<<answer[i]<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();
    prepare();
    print_ans();
	return 0;
}
