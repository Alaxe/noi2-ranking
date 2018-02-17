#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define NMax 100000

struct vert_segment
{
    long long x;
    long long y1,y2;

    vert_segment(){};
    vert_segment(long long a,long long b,long long c)
    {
        x=a,y1=b,y2=c;
    }
} vseg[NMax+5];

long long w,h,n,px[NMax+5],py[NMax+5],cur,ans;
bool used[10000005];

bool cmp1(vert_segment a,vert_segment b)
{
    return a.x>b.x;
}

int main()
{
    scanf("%lld%lld%lld",&w,&h,&n);

    for(long long i=0;i<n;i++)
        scanf("%lld%lld",&px[i],&py[i]);

    for(long long i=0;i<n;i++)
    {
        long long k=i;
        while(i<n&&px[i]==px[k])i++;

        i--;

        vseg[cur++]=vert_segment(px[k],max(py[k],py[i]),min(py[k],py[i]));
    }

    sort(vseg,vseg+cur,cmp1);

    ans+=vseg[0].x*(vseg[0].y1-vseg[0].y2);

    for(long long i=1;i<cur;i++)
    {
        long long cnt=0;
        for(long long j=vseg[i].y2;j<vseg[i].y1;j++)
            if(used[j]==0)used[j]=1,cnt++;
        ans+=cnt*vseg[i].x;
    }

    printf("%lld\n",w*h-ans);

    return 0;
}
/**
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
