#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

#define NMax 100000
#define MMax 100000
#define Base 149
#define Mod 1000000007LL

int w, k, n, m;
int a[NMax + 2], b[MMax + 2];
map<long long, int> cnta;
long long ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> k;

    long long Btok = 1LL;

    for(int i = 0; i < k - 1; i ++)
    {
        Btok *= Base;
        Btok %= Mod;
    }

    cin >> n;
    long long hasha = 0, conseq = 1;

    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];

        if(w == 1)
        {
            if(i != 0 && a[i] > a[i - 1]) conseq ++;
            else if(i != 0 && a[i] <= a[i - 1]) conseq = 1;
        }
        else
        {
            if(i != 0 && a[i] == a[i - 1]) conseq ++;
            else if(i != 0 && a[i] != a[i - 1]) conseq = 1;
        }

        if(i < k) hasha = (hasha * Base + a[i]) % Mod;
        else
        {
            if(hasha < (Btok * a[i - k]) % Mod) hasha += Mod;
            hasha = ((hasha - (Btok * a[i - k]) % Mod) * Base + a[i]) % Mod;
        }
        if(i >= k - 1 && conseq >= k) cnta[hasha] ++;
    }

    cin >> m;
    long long hashb = 0;
    conseq = 1;

    for(int i = 0; i < m; i ++)
    {
        cin >> b[i];

        if(w == 1)
        {
            if(i != 0 && b[i] > b[i - 1]) conseq ++;
            else if(i != 0 && b[i] <= b[i - 1]) conseq = 1;
        }
        else
        {
            if(i != 0 && b[i] == b[i - 1]) conseq ++;
            else if(i != 0 && b[i] != b[i - 1]) conseq = 1;
        }

        if(i < k) hashb = (hashb * Base + b[i]) % Mod;
        else
        {
            if(hashb < (Btok * b[i - k]) % Mod) hashb += Mod;
            hashb = ((hashb - (Btok * b[i - k]) % Mod) * Base + b[i]) % Mod;
        }

        if(i >= k - 1 && conseq >= k && cnta.count(hashb) != 0)
            ans += cnta[hashb];
    }

    cout << ans << endl;

    return 0;
}
/**
1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
/**
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
*/
