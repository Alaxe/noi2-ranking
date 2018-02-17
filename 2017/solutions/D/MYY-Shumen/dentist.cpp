#include <iostream>
using namespace std;
const int maxn=1<<20;
int cnt[maxn];
int main()
{
    int i,start,time;
    int maxt=0;
    while (cin>>start>>time)
    {
        cnt[start]+=time;
        if (start>maxt)maxt=start;
    }
    int answer=0;
    int tt=0;
    for (i=0;i<maxn;i++)
    {
        if (tt>0)answer=i;
        tt+=cnt[i];
        if (tt>0)tt--;
    }
    cout<<answer+1-maxt<<endl;
return 0;
}
