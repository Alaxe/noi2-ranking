#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n;
    cin >> k;
    unsigned long long p = 1;
    if(k == 1 || k == n)
    {
        cout << 1 << endl;
        return 0;
    }
    if(n-k > k-1)
    {
        for(int i = 1; i < k; i ++)
        {
            p *= (n-i);
        }
    }

    else
    {
        int j = 1;
        for(int i = k; i < n; i ++)
        {
            p *= (n-j);
            j ++;
        }
    }
    cout << p << endl;
    return 0;
}
