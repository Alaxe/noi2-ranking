#include <iostream>

using namespace std;

long long Sum(long long a)
{
    long long ans = 0;
    while (a > 0)
    {
        ans += a % 10;
        a /= 10;
    }
    return ans;
}

int main()
{
    long long n, sum = 1;

    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        sum *= i;
    }
    cout << Sum(sum) << endl;
    return 0;
}
