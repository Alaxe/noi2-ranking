#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct cell
{
    bool x;
    vector<int>v;
};
int n,w1,w2;
int used[256];
cell t1[256];
int t2[256];
int a[256];
cell t[256];
int maxsum=0;
bool merge_cell(cell x1,cell y)
{
    int used1[128];
    memset(used1,0,sizeof(used1));
    int sz=x1.v.size();
    int sz1=y.v.size();
    for(int i=0; i<sz; i++)
    {
        used1[x1.v[i]]++;
    }
    for(int i=0; i<sz1; i++)
    {
        used1[y.v[i]]++;
    }
    for(int i=1; i<=100; i++)
    {
        if(used1[i]>used[i])
        {
            return 0;
        }
    }
    return 1;
}
void read()
{
    cin>>n>>w1>>w2;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        used[a[i]]++;
        t1[a[i]].x=1;
        t1[a[i]].v.push_back(a[i]);
    }

}
void solve()
{

    for(int i=2; i<=n; i++)
    {
        for(int j=w1; j>=1; j--)
        {
            if(t1[j].x==0)
            {
                for(int k=1; k<=n; k++)
                {
                    int r=a[k];
                    int p=j-r;
                    if(p>=1 && p<=w1)
                    {
                        if(t1[p].x==1)
                        {
                            if(merge_cell(t1[p],t1[r]))
                            {
                                t1[j].x=1;
                                t1[j]=t1[p];
                                int sz=t1[r].v.size();
                                for(int f=0; f<sz; f++)
                                {
                                    t1[j].v.push_back(t1[r].v[f]);
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    int r1=0;
    for(int i=w1; i>=1; i--)
    {
        if(t1[i].x==1)
        {
            r1=i;
            break;
        }
    }

    if(r1>0)
    {
        maxsum+=r1;
        int sz=t1[r1].v.size();

        for(int i=0; i<sz; i++)
        {
            used[t1[r1].v[i]]--;

        }
    }
}
void solve2()
{
    for(int i=1; i<=100; i++)
    {
        if(used[i]>0)
        {
            if(i<=w2)
            {
                t[i].x=1;
                t[i].v.push_back(i);

            }
        }
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=w2; j>=1; j--)
        {
            if(t[j].x==0)
            {
                for(int k=1; k<=n; k++)
                {
                    int r=a[k];
                    int p=j-r;
                    if(p>=1 && p<=w2 && used[r]>0)
                    {
                        if(t[p].x==1)
                        {

                            if(merge_cell(t[p],t[r])==1)
                            {
                                t[j].x=1;
                                t[j]=t[p];
                                int sz=t[r].v.size();
                                for(int f=0; f<sz; f++)
                                {
                                    t[j].v.push_back(t[r].v[f]);
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    int r1=0;
    for(int i=w2; i>=1; i--)
    {
        if(t[i].x==1)
        {
            r1=i;
            break;
        }
    }
    maxsum+=r1;
    cout<<maxsum<<endl;

}
int main()
{
    read();
    solve();
    solve2();

    return 0;
}
