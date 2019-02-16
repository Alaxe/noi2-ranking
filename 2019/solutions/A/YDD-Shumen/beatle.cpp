#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX_N=100005;
int n, t;
struct lines
{
    int x, y, d, lbr, rbr;
    lines () {};
    lines (int x_, int y_, int d_, int lbr_, int rbr_)
    {
        x=x_;
        y=y_;
        d=d_;
        lbr=lbr_;
        rbr=rbr_;
    }
};
lines l[MAX_N];
bool cmp(lines lhs, lines rhs)
{
    if(lhs.y>rhs.y)
        return 0;
    return 1;
}
void solve()
{
    for(int i=1; i<n; i++)
    {
        bool lamp=false;
        for(int j=i; j>=0; j--)
        {
            if(l[j].y<l[i].y)
            {
                if(l[i].x>l[j].x&&l[i].x<=l[j].x+l[j].d&&l[i].lbr==0)
                    l[i].lbr=min(l[j].lbr, l[j].rbr)+1;
                if(l[i].x+l[i].d>=l[j].x&&l[i].x+l[i].d<l[j].x+l[j].d&&l[i].rbr==0)
                    l[i].rbr=min(l[j].lbr, l[j].rbr)+1;
                if(l[i].rbr!=0&&l[i].lbr!=0)
                    j=-1;
            }
        }
    }
    //printf("------------\n");
}
void print()
{
    for(int i=0; i<n; i++)
        printf("%d %d %d - %d\n", l[i].x, l[i].y, l[i].d, i);
}
void read()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &l[i].x, &l[i].y, &l[i].d);
        l[i].lbr=0;
        l[i].rbr=0;
    }
    sort(l, l+n, cmp);
    solve();
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        bool lamp=false;
        int a;
        scanf("%d", &a);
        for(int j=n-1; j>=0; j--)
        {
            if(l[j].x<=a&&l[j].x+l[j].d>a)
            {
                printf("%d ", min(l[j].lbr, l[j].rbr)+1);
                j=-1;
                lamp=true;
            }
            if(j==0&&lamp==false)
                printf("0 ");
        }
    }
    printf("\n");
}
int main()
{
    //freopen("input.txt", "r", stdin);
    read();
    return 0;
}
