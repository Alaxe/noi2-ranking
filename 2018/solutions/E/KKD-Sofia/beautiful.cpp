#include<iostream>
using namespace std;

long long n, k;

int main()
{
    cin >> n >> k;
    if (n == 1)
    {
        long long num = k;
        if (num >= 10)
        {
            cout << "NO\n";
        }
        else
        {
            cout << num << '\n';
        }
    }
    else
    {
        int brCifri = 1;
        long long num = 1;
        while (brCifri < n)
        {
            num *= 10;
            brCifri ++;
        }
        if (k >= num * 10)
        {
            cout << "NO\n";
            return 0;
        }
        if (num % k == 0)
        {
            cout << num << '\n';
        }
        else
        {
            cout << num % k << '\n';
            cout << num - num % k + k << '\n';
        }
    }
    return 0;
}
