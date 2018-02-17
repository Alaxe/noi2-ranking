#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
    int x, y;
} p[1001];
struct line
{
    double k, b;
} ks[1000001];
int n,s,br=1,tmp;
bool cmp (line a, line c)
{
    if (a.k!=c.k) return a.k<c.k;
    return a.b<c.b;
}
int main ()
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d%d",&p[i].x,&p[i].y);
    if (n==2)
    {
        printf("2\n");
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if (p[j].x==p[i].x)
            {
                ks[s].k=10000;
                ks[s].b=10000;
            }
            else
            {
                ks[s].k=(double)(p[j].y-p[i].y)/(double)(p[j].x-p[i].x);
                ks[s].b=(double)(p[i].y-ks[s].k*p[i].x);
            }
            s++;
        }
    }
    sort(ks,ks+s,cmp);
    for (int i=1; i<s; i++)
    {
        if(ks[i].k==ks[i-1].k && ks[i].b==ks[i-1].b) br++;
        else
        {
            if (br>tmp) tmp=br;
            br=1;
        }
    }
    int maxlen=1;
    while(tmp!=0)
    {
        tmp-=maxlen;
        maxlen++;
    }
    printf("%d\n",maxlen);
}
