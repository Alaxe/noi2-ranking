#include<bits/stdc++.h>
using namespace std;

int k, m, n;

int f(int x, int N)
{
    if(N==1)
        return 1;
    else if(x - k <= 0)
        return f(x + k, N - 1);
    else if(x + k >= m)
        return f(x - k, N - 1);
    else return f(x - k, N - 1) + f(x + k, N - 1);
}

int main ()
{
    cin >> k >> m >> n;
    long long sum = 0;

    for(int i = 1; i < m; i++)
        sum += f(i, n);

    cout << sum << endl;

    return 0;
}
