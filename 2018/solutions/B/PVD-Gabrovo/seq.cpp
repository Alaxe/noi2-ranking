#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;

uint64_t mem [271][271];

uint64_t n, m;

uint64_t rec(/*uint16_t len, */uint64_t sum, uint64_t last)
{
    if(sum>n)return 0;
    //cout<<len<<' '<<sum<<' '<<last<<endl;
    if(sum==n)return 1;
    if(mem[sum][last]!=0)return mem[sum][last];
    uint64_t res=0;
    for(uint64_t i=1; i<=min(m, last); i++)
    {
        res+=rec(/*len+1, */sum+i, i);
    }

    return (mem[sum][last]=res);
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
}

int main()
{
    init();
    cout<<rec(/*0, */0, UINT16_MAX)<<endl;

    return 0;
}
