#include<iostream>
#include<queue>
using namespace std;

unsigned long long k,n,first,mul,add;
int mod;
unsigned long long int ans=0;
struct Comparator
{
operator ()( pair<int, int> &p1, pair<int, int> &p2)
{
    if(p1.first==p2.first) return p1.second>p2.second;
    return p1.first<p2.first;
}
};
int main()
{
    cin>>n>>k>>first>>mul>>add>>mod;
    priority_queue<pair<int, int>, vector<pair<int, int> > , Comparator >pq;
    int a = first;
    pq.push(make_pair(a,0));
    ans+=a;
    pair<int, int> top = pq.top();
    for(int i=1;i<n;i++)
    {
        a = ((a*mul)+add)%mod;
        pq.push(make_pair(a,i));
        while(pq.top().second+k<=i) pq.pop();
        top = pq.top();
        ans+=top.first;
    }
    cout<<ans<<endl;
    return 0;
}
