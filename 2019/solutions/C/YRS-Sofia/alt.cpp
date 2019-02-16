#include <iostream>
using namespace std;
long long dp[50][2];
long long dob, limit, len;
long long getsum(long long i, long long z)
{
    long long sum = 0;
    if(z - dob > 0) sum += dp[((i - 1) & 1)][z - dob];
    if(z + dob < limit) sum += dp[((i - 1) & 1)][z + dob];
    return sum;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> dob >> limit >> len;
    for(long long i = 1; i <= len; ++i){
        for(long long z = 1; z < limit; ++z){
            if(i == 1){
                dp[(i & 1)][z] = 1;
                //cout << i << ' ' << z << ' ' << dp[i % 2][z] << '\n';
                continue;
            }
            dp[(i & 1)][z] = getsum(i, z);
            //cout << i << ' ' << z << ' ' << dp[i % 2][z] << '\n';
        }
    }
    long long res = 0;
    for(long long z = 1; z < limit; ++z){
        res += dp[(len & 1)][z];
    }
    cout << res << '\n';
    return 0;
}
