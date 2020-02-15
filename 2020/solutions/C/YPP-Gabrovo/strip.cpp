#include <iostream>
#define endl '\n'
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    unsigned long long int ans = 1;
    int x = min(n - k, k - 1);
    for (int i = 1; i <= x; ++ i)
        ans = 1ll * ans * (n - i) / i;

    cout << ans << endl;

    return 0;
}
