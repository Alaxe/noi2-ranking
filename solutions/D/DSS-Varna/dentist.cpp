#include<bits/stdc++.h>
using namespace std;
struct pc
{
    int st;
    int k;
    int fn;
};
bool cmp(pc a,pc b)
{
    return a.st<b.st;
}
pc n[1500];
int main()
{
    int brp=0,p=0;
    for(int i=0;; i++)
    {
        cin>>n[i].st>>n[i].k;
        if(cin.eof()) break;
        n[i].fn=n[i].st+n[i].k;
        brp++;
    }
    sort(n,n+brp,cmp);
    for(int i=1; i<brp; i++)
    {
        if(n[i-1].fn>n[i].st)
        {
            n[i].fn+=(n[i-1].fn-n[i].st);
            p=(n[i-1].fn-n[i].st);
        }
    }
    cout<<p+n[brp-1].k<<endl;
}
/*
0 30
720 10
715 20
714 25
*/
