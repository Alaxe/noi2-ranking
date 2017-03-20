#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
typedef unsigned long long uint64_t;

vector<int> digits;
int n;
uint64_t mod;

void read()
{
    string s;
    cin>>s;
    cin>>n>>mod;
    digits.resize(s.size());
    for(int i=0;i<digits.size();i++)
    {
        digits[i]=s[i]-'0';
    }
}

void solve()
{
    vector<uint64_t> rems(n, 0);
    vector<uint64_t> toAdd(n);

    rems[digits.front()%n]++;
    rems[0]++;

    for(int i=1;i<digits.size();i++)
    {

        //printf("i: %d\n", i);
        uint64_t digit=digits[i];

        for(int j=0;j<n;j++)toAdd[j]=0;

        for(uint64_t prevRem=0;prevRem<n;prevRem++)
        {
            uint64_t rem=(prevRem*10LL+digit)%n;
            toAdd[rem]+=rems[prevRem];
            toAdd[rem]%=mod;
        }

        for(int j=0;j<n;j++)rems[j]+=toAdd[j];
    }

    printf("%llu\n", (rems[0]+mod-1)%mod);
    //exit(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read();
    solve();
}
/**
1234
4 2

222
2 10

02
2 10
*/
