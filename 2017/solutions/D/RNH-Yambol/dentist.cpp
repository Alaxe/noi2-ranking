#include<stdio.h>
#include<vector>
using namespace std;
vector<long long> p;
vector<long long> l;
long long m=0,pm=0;
void max()
{
    long long i;
    for(i=0; i<p.size(); i++)
    {
        if(p[i]>p[m]) m=i;
    }
}
void preMax()
{
    long long i;
    for(i=0; i<p.size(); i++)
    {
        if((p[i]>p[pm])&&(p[i]!=p[m])) pm=i;
    }
}
int main()
{
    long long ip,il;
    while(scanf("%lld %lld",&ip,&il)==2)
    {
        p.push_back(ip);
        l.push_back(il);
    }
    max();
    preMax();
    if((p[m]-p[pm]>=l[pm])&&(l[m]>l[pm])) printf("%lld\n",l[m]);
    else
    {
        long long s=0,i;
        for(i=0; i<p.size(); i++)
        {
            s=s+(p[m]-p[i]);
        }
        if(l[m]<l[pm]) s=s+(l[m]-l[pm]);
        s=s+l[m];
        printf("%lld\n",s);
    }
    return 0;
}
