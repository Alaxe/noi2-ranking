#include<bits/stdc++.h>
#define ull unsigned long long
#define LILI_E_GOTINA int
///twitch.tv/bili220022
/**
DM me jordan.iliev501@gmail.com
*/
using namespace std;
ull lili[10000][2];
LILI_E_GOTINA main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LILI_E_GOTINA n;
    cin>>n;
    short curr;
    LILI_E_GOTINA K=0;
    queue<LILI_E_GOTINA> Q;
    for(LILI_E_GOTINA i=0;i<n;++i)
    {
        cin>>curr;
        Q.push(curr);
        K=max(K,curr+1);
    }
    for(LILI_E_GOTINA i=0;i<n;++i)
    {
        curr=Q.front();
        Q.pop();
        lili[1][i&1]=lili[1][(i&1)^1]+curr-1;
        for(short j=2;j<=K;++j)
        {
            lili[j][i&1]=min(lili[j-1][i&1],lili[j][(i&1)^1]+abs(curr-j));
        }
    }
    cout<<lili[K][(n&1)^1]<<endl;
    return 0;
}


