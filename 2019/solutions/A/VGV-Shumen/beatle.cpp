#include <bits/stdc++.h>
using namespace std;
int n,t;
struct Lines
{
    int x,y,d,lbr,rbr;
    Lines(){};
    Lines(int x1, int y1,int d1, int lbr1,int rbr1)
    {
        x=x1;
        y=y1;
        d=d1;
        lbr=lbr1;
        rbr=rbr1;
    }
};
Lines l[100000];
bool cmp(Lines lhs, Lines rhs)
{
    if(lhs.y>rhs.y) return 0;
    else return 1;
}
void Solve()
{
    for(size_t i=1;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(l[j].y<l[i].y)
            {
                if(l[i].x>l[j].x&&l[i].x<=l[j].x+l[j].d&&l[i].lbr==0) l[i].lbr=min(l[j].lbr,l[j].rbr)+1;
                if(l[i].x+l[i].d>=l[j].x&&l[i].x+l[i].d<l[j].x+l[j].d&&l[i].rbr==0) l[i].rbr=min(l[j].lbr,l[j].rbr)+1;
                if(l[i].rbr!=0&&l[i].lbr!=0)
                {
                    j=-1;
                }
            }
        }
    }
}
void Read()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>l[i].x>>l[i].y>>l[i].d;
        l[i].lbr=0; l[i].rbr=0;
    }
    sort(l,l+n,cmp);
    Solve();
    cin>>t;
    for(size_t i=0;i<t;i++)
    {
        bool lamp=false;
        int a;
        cin>>a;
        for(int j=n-1;j>=0;j--)
        {
            if(l[j].x<=a&&l[j].x+l[j].d>a)
            {
                cout<<min(l[j].lbr,l[j].rbr)+1<<" ";
                j=-1;
                lamp=true;
            }
            if(j==0&&lamp==false) cout<<0<<" ";
        }
    }
}
int main()
{
    Read();
    return 0;
}
