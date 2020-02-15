#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair <int, int>
using namespace std;
const int N = 1e5 + 5;

int n, a[N];
priority_queue <int> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!pq.empty() && pq.top() > a[i])
        {
            ans += pq.top() - a[i];
            pq.pop();
            pq.push(a[i]);
        }
        pq.push(a[i]);
    }

    cout << ans << endl;

    return 0;
}

/*

5
2 6 4 3 2

5
2 6 6 7 7

*/
