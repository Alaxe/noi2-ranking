#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct rolling_hash
{
    static const long long MOD1 = 1e9+7/*2000029*/, MOD2 = 1e9+9/*2000039*/, MAXA = 2000003;
    long long hash1, hash2;
private:
    int* arr, start_index, n;
    long long f1;
    long long f2;
public:
    void init (int* a, int s, int n)
    {
        arr = a;
        start_index = s;
        this->n = n;

        hash1 = hash2 = 0;
        f1 = f2 = 1;
        for (int i = 0 ; i < n ; i ++)
        {
            hash1 = (hash1 * MAXA + a [s + i]) % MOD1;
            hash2 = (hash2 * MAXA + a [s + i]) % MOD2;
            if (i > 0)
            {
                f1 = (f1 * MAXA) % MOD1;
                f2 = (f2 * MAXA) % MOD2;
            }
        }
    }
    void roll ()
    {
        hash1 = (((hash1 + MOD1 - (arr [start_index] * f1) % MOD1) % MOD1) * MAXA + arr[start_index + n]) % MOD1;
        hash2 = (((hash2 + MOD2 - (arr [start_index] * f2) % MOD2) % MOD2) * MAXA + arr[start_index + n]) % MOD2;
        start_index ++;
    }

    bool operator == (const rolling_hash& h) const
    {
        return this->hash1 == h.hash1 and this->hash2 == h.hash2;
    }

    bool operator < (const rolling_hash& h) const
    {
        return this->hash1 < h.hash1 or (this->hash1 == h.hash1 and this->hash2 < h.hash2);
    }

    bool operator > (const rolling_hash& h) const
    {
        return this->hash1 > h.hash1 or (this->hash1 == h.hash1 and this->hash2 > h.hash2);
    }
};

ostream& operator << (ostream& out, const rolling_hash& a)
{
    out << "(" << a.hash1 << "," << a.hash2 << ")";
    return out;
}

int a [100000], b [100000];

map < rolling_hash, int > count_seq;
map < int, int > count_eq_seq;

int solve1 (int, int, int);
int solve2 (int, int, int);

int main ()
{
    cin.tie (nullptr);
    ios::sync_with_stdio(false);
    int type, k, n, m;
    cin >> type >> k;
    cin >> n;
    for (int i = 0 ; i < n ; i ++)
        cin >> a [i];
    cin >> m;
    for (int i = 0 ; i < m ; i ++)
        cin >> b [i];

    if (type == 2)
        cout << solve2 (k, n, m) << endl;
    else
        cout << solve1 (k, n, m) << endl;
    return 0;
}

int solve1 (int k, int n, int m)
{
    int res = 0;
    rolling_hash hash;
    hash.init (a, 0, k);
    count_seq [hash] ++;
    for (int i = k ; i < n ; i ++)
    {
        hash.roll();
        count_seq [hash] ++;
    }
    hash.init (b, 0, k);
    res += count_seq [hash];
    for (int i = k ; i < m ; i ++)
    {
        hash.roll();
        res += count_seq [hash];
    }
    return res;
}

int solve2 (int k, int n, int m)
{
    int res = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        int j = i + 1;
        while (a [i] == a [j])
            j ++;
        if (j - i - k + 1 > 0)
            count_eq_seq [a [i]] += j - i - k + 1;
        i = j - 1;
    }
    for (int i = 0 ; i < m ; i ++)
    {
        int j = i + 1;
        while (b [i] == b [j])
            j ++;
        if (j - i - k + 1 > 0)
            res += (j - i - k + 1) * count_eq_seq [b [i]];
        i = j - 1;
    }
    return res;
}


/**
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
