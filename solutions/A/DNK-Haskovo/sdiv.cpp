//
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<climits>
#include<stack>
#include<set>

#define lli long long

using namespace std;


lli a[10000],b[10000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    lli n,m;
    cin>>n>>m;


    for(int j=0;j<s.size();j++)
    {
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            b[(i*10+s[j]-'0')%n]+=a[i];
            if(b[(i*10+s[j]-'0')%n]>=m)b[(i*10+s[j]-'0')%n]%=m;
        }
        b[(s[j]-'0')%n]++;

        for(int i=0;i<n;i++)
        {

            a[i]+=b[i];
            if(a[i]>=m)a[i]%=m;
        }
    }
    cout<<a[0]<<"\n";
    return 0;
}
