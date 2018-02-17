#include<iostream>
#include<queue>
using namespace std;
struct patient
{
    int b,l;
    bool operator < (const patient &p) const
    {
        return b>p.b;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    int b,l;
    priority_queue<patient> q;
    while(cin>>b>>l)
    {
        patient p;
        p.b=b;
        p.l=l;
        q.push(p);
    }
    int tek=0; patient last;
    while(!q.empty())
    {
        last=q.top(); q.pop();
        if(tek<=last.b) tek=last.b+last.l;
        else if(tek>last.b) tek+=last.l;
        //cout<<tek<<endl;
    }
    cout<<tek-last.b<<endl;
    return 0;
}
