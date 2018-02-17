#include<bits/stdc++.h>
using namespace std;

long long n, k, dob = 1, t;

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n - 1; i ++)
        dob *= 10;
        t = dob * 10;
    dob %= k;
    dob = k - dob;
    if(dob % k != 0)cout << t + dob << endl;
    else cout << t << endl;
}
