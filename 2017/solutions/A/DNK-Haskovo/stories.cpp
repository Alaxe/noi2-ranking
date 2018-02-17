//
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<deque>
#include<string>
#include<iomanip>
#include<climits>
#include<stack>
#include<set>

#define lli long long

using namespace std;


deque<lli>Q,Q1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    lli k,mul,add,mod,ans=0;

    cin>>k>>mul>>add>>mod;

    ans=k;
    Q.push_back(k);
    Q1.push_back(1);

    for(int i=2;i<=n;i++)
    {
        k=(k*mul+add);
        if(k>=mod)k%=mod;


        while(Q.back()<=k)
        {
            Q.pop_back();
            Q1.pop_back();
            if(Q.empty())break;
        }

        Q.push_back(k);
        Q1.push_back(i);

        while(Q1.front()+m<=i)
        {
            Q.pop_front();
            Q1.pop_front();
        }

        ans+=Q.front();

    }
    cout<<ans<<"\n";
    return 0;
}
