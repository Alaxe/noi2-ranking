#include <iostream>
using namespace std;
const int mod = 1073741824;
unsigned int p, q, m, n, ans = 0, dp [11000][2];
int main (){

    cin >> m >> n >> q >> p;
    dp [m][0] = 1;
    for (int i = m + 1; i < n; i ++){
        dp [i][0] = (dp [i - q][0] + dp [i - q][1]) % mod;
        dp [i - p][1] = dp [i][0];
    }
    for (int i = 0; i < q; i ++){
        dp [n + i][0] = (dp [n + i - q][0] + dp [n + i - q][1]) % mod;
        ans = (ans + dp [n + i][0]) % mod;
    }
    cout << ans << '\n';

    return 0;
}
