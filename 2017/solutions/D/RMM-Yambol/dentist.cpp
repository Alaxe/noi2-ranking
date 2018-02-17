# include <iostream>
# include <cstdio>
# include <fstream>
# include <algorithm>
using namespace std;
struct ff
{
    int f;
    int s;
};
ff a[1000];

bool cmp(ff i, ff j)
{
   return(i.f<=j.f);
}
int main()
{int i,j,n;
i=1;
while(scanf("%d%d",&a[i].f,&a[i].s)==2)
{
i++;
}
n=i-1;
sort(a+1,a+1+n,cmp);

int time=0;
for(i=1;i<=n;i++)
{
    time=max(time,a[i].f);
    time+=a[i].s;
}
printf("%d\n",time-a[n].f);
return 0;
}
