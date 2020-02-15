#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector <int> v;
    v.resize(n);

    for (int i = 0; i != n; i ++)
    {
        cin>>v[i];
    }
    int last = -1;
    for (int i = 0; i != n; i ++)
    {
        if (last > v[i])
        {
            cout<<abs(last - v[i]);

        }
        last = v[i];
    }

    return 0;
}
