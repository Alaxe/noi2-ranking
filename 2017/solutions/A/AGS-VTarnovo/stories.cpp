#include <iostream>
#include <vector>
using namespace std;

vector<long long>v[2];

int main()
{
    ios::sync_with_stdio(false);
    long long n,k,first,mul,add,mod,x,last,ans=0,br=0,r;
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
    v[0].push_back(first);
    v[1].push_back(0);
    ans+=first;
    last=first;
    for(int i=1;i<n;i++)
    {
        x=(last*mul+add)%mod;
        while(x>v[0][v[0].size()-1]&&v[0].size()>br)
        {
            v[0].pop_back();
            v[1].pop_back();
        }
        v[0].push_back(x);
        v[1].push_back(i);
        while((i-v[1][br])>=k)br++;
        ans+=v[0][br];
        last=x;
    }
    cout<<ans<<endl;
    return 0;
}

