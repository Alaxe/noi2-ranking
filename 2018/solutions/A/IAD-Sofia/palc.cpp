#include <iostream>
#define MOD 1000000007
using namespace std;
string inp;
long long solve(int f, int t)
{
    //cout << f << " " << t << endl;
    if(t == f) return 1;
    if(t-f == 1) return 2;
    long long ans = 0;
    for(int i = f; i < t-1; i ++)
    {
        for(int j = i+1; j < t; j ++)
        {
            if(inp[i] == inp[j]) ans += solve(i+1, j);
            ans %= MOD;
        }
    }
    if(ans == 0)
    {
        int curr = t-f;
        for(int i = 1; i <= t-f; i ++)
        {
            ans += curr;
            ans %= MOD;
            curr *= t-f-i;
            curr /= i+1;
        }
    }
    //cout << "=" << ans << endl;
    return ans%MOD;
}
int main()
{
    cin >> inp;
    cout << (solve(0, inp.size())+inp.size())%MOD << endl;
}

