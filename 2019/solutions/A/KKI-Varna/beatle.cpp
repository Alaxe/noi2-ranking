#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct daska
{
    int x1,x2, y;
} m[MAXN];
struct str
{
    int pos, d;
};
vector<str> v;
bool cmp(daska a, daska b)
{
    if(a.y!=b.y)return a.y<b.y;
    if(a.x1!=b.x1) return a.x1<b.x1;
    return a.x2<b.x2;
}

int findd(int pos)
{
    int t=v.size()-1;
    while(v[t/2].pos>pos)t=t/2;
    while(v[t].pos>pos)t--;
    return v[t].d;
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    int n;
    cin>>n;
    int a,b,c;
    daska d;
    int maxa=0;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b>>c;
        d.x1=a;
        d.y=b;
        d.x2=a+c;
        m[i]=d;
        maxa=max(maxa, d.x1);
        maxa=max(maxa, d.x2);
    }
    sort(m,m+n, cmp);
    str y;
    y.pos=0;
    y.d=0;
    v.push_back(y);
    y.pos=maxa;
    y.d=0;
    v.push_back(y);
    int dylb1=0;
    int dylb2=0;
    stack<str> st;
    int x1,x2;
    int prevd=0;
    for(int i=0; i<n; i++)
    {
        x1=m[i].x1;
        x2=m[i].x2;
        dylb1 = findd(x1-1);
        dylb2 = findd(x2);
        y.d=min(dylb1,dylb2)+1;
        y.pos=x1;
        prevd=findd(x2);
        while(!v.empty()&&v[v.size()-1].pos>=x1)
        {
            if(v[v.size()-1].pos>=x2)st.push(v[v.size()-1]);
            v.pop_back();
        }
        v.push_back(y);
        if(st.top().pos>x2)
        {
            y.pos=x2;
            y.d=prevd;
            v.push_back(y);
        }
        while(!st.empty())
        {
            if(st.top().pos<x2||st.top().d==v[v.size()-1].d)
            {
                st.pop();
                continue;
            }
            v.push_back(st.top());
            st.pop();
        }
    }
    int tests=0;
    cin>>tests;
    for(int t=0; t<tests; t++)
    {
        cin>>a;
        cout<<findd(a)<<" ";
    }
    cout<<endl;
}

/***
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2


*/
