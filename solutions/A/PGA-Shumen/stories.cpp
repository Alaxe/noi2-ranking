#include<iostream>
#include<queue>
#include<map>
using namespace std;
priority_queue<int> q;
queue<long long> qq;
map<int,int> m;
long long n,k,first,mul,add,mod;
int main()
{
    int i,j;
    long long s=0;
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
    m[first]++;
    s+=first;
    q.push(first);
    qq.push(first);
    long long next;
    long long w;
    for(i=2;i<=n;i++)
    {
        next=(first*mul+add)%mod;
        first=next;
        m[next]++;
        q.push(next);
        qq.push(next);
        if(i>k)
        {
            w=qq.front();
            qq.pop();
            m[w]--;
        }
        while(1)
        {
            w=q.top();
            if(m[w]==0) q.pop();
            else break;
        }
        w=q.top();
        s+=w;
    }
    cout<<s<<endl;
    return 0;
}
