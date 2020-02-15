#include<bits/stdc++.h>
using namespace std;
int perms = 1;
inline int permutations(int n, int b, int e)
{
    if(b == 0 || e == n - 1)
    {
        return 0;
    }
    else
    {
        perms += 1;
        permutations(n, b - 1, e);
        permutations(n, b, e + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    permutations(n, k - 1, k - 1);
    cout << perms << endl;




    return 0;
}
