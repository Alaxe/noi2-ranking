#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int maxa,mina,n,cnt[maxn],p[maxn];
void read()
{
    int a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        maxa=max(maxa,a);
        mina=min(mina,a);
        cnt[a]++;
    }
    /*for(int i=1;i<=maxa;i++)
        printf("%d ",cnt[i]);
    printf("\n");*/
}
void init_p()
{
    p[0]=0;
    for(int i=1;i<=maxa;i++)
    {
        ///cout<<p[i-1]<<endl;
        p[i]=p[i-1]+cnt[i];
    }
    /*for(int i=1;i<=maxa;i++)
        printf("%d ",p[i]);
    printf("\n");*/
}
int cnt_nums(int i,int j)
{
    return p[j]-p[i-1];
}
void solve()
{
    int m,l,r,rez;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&l,&r);
        if(l>maxa)printf("0\n");
        else
        {
            if(r<mina)printf("0\n");
            else
            {
                if(r>maxa)
                {
                    rez=cnt_nums(l,maxa);
                    printf("%d\n",rez);
                }
                else
                {
                    rez=cnt_nums(l,r);
                    printf("%d\n",rez);
                }
            }
        }
    }
}
int main ()
{
    read();
    init_p();
    solve();
return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/
/*
18
10 1 20 7 8 1 3 7 28 9 15 17 14 2 4 2 6 23
8
1000 10000
5 9
10 27
2 7
1 3
9 9
520 1010
26 37
*/
