#include<iostream>
using namespace std;

long long n;
long long q;
long long maxH = 0;
long long ans;

int main()
{
    cin >> n;
    long long flowers[n];
    for (int i = 0; i < n; i ++)
    {
        cin >> flowers[i];
        if (flowers[i] > maxH)
        {
            maxH = flowers[i];
        }
    }
    cin >> q;
    for (int i = 0; i < n; i ++)
    {
        cout << maxH << ' ' << (maxH - flowers[i]) * q << '\n';
        ans += (maxH - flowers[i]) * q;
    }
    cout << ans << '\n';
    return 0;
}
