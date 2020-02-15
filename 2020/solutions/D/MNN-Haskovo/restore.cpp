#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[100005], b[100005], num[100005], i;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, i, j, br;
    cin >> n;
    br = n;
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
        num[i]=n-i;
    }
    for (i = 0; i < n; i++)
    {
        a[i]=num[b[i]];
        for (j = b[i]; j < br; j++)
        {
            num[j] = num[j+1];
        }
        br--;
    }
    cout << a[0];
    for (i = 1; i < n; i++)cout << " " << a[i];
    cout << endl;
    return 0;

}
/*
6
2 3 0 0 1 0
*/
