#include <iostream>
#define MOD 123456789012345
using namespace std;
int nums[2003], pos[2003][2003];
int len[2003], mx = 0;
int n;
unsigned long long ans[2003];
int d;
long long fnd(int curr)
{

    //cout << curr << endl;
    if(nums[curr] == mx) return 0;
    if(ans[curr] > 0) return ans[curr];
    long long ret = 0;
    for(int i = 0; i < len[nums[curr]+d]; i ++)
    {
        if(pos[nums[curr]+d][i] > curr) ret += fnd(pos[nums[curr]+d][i])+1;
        ret %= MOD;
    }
    ans[curr] = ret;
    return ret;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        pos[nums[i]][len[nums[i]] ++] = i;
        mx = max(mx, nums[i]);
    }
    unsigned long long fin = 0;
    for(d = 1; d < mx; d ++)
    {
        for(int i = 0; i < 1001; i ++) ans[i] = 0;
        for(int i = 0; i < n; i ++) fnd(i);
        for(int i = 0; i < n; i ++)
        {
            fin += ans[i];
            fin %= MOD;
        }
    }
    cout << fin << endl;
}
