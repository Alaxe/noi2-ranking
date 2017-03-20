#include <bits/stdc++.h>
using namespace std;
struct pat
{
    int m,t;
    int m1;
}s[10000];
bool f(pat x, pat y)
{
    if(x.m<y.m && x.t!=0 && y.t!=0)return 1;
    return 0;
}
int main()
{
    int brp=0;
    int p=0;
    for(int i=0;;i++)
    {
        cin>>s[i].m>>s[i].t;
        brp++;
        if(!cin)break;
    }
    sort(s,s+brp,f);
    for(int i=0;i<brp;i++)
    {
        s[i].m1=s[i].m;
        if(s[i-1].m<s[i].m)
        s[i].m+=s[i].t+p;
        else
            s[i].m+=s[i].t+p+(s[i-1].m-s[i].m);
    }
    cout<<s[brp-1].m-s[brp-2].m1<<endl;
    return 0;
}
/**
0 30
720 10
715 20
714 25
*/
