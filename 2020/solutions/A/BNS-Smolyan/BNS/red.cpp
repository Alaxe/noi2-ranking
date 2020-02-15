#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int w, k;
int n, m;
int a[MAXN], b[MAXN];

void read_input()
{
    scanf("%d %d", &w, &k);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
}

const int MOD[3] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 3};
const int BASE[3] = {19, 23, 29};

int add(int f, int s, int m)
{
    f += s;
    if(f >= m)
    {
        f %= m;
    }
    return f;
}

int mul(int f, int s, int m)
{
    long long temp = 1LL * f * s;
    if(temp >= m)
    {
        temp %= m;
    }
    return temp;
}

int del(int f, int s, int m)
{
    f -= s;
    if(f < 0) f += m;
    return f;
}

int pw[3][MAXN * 10];

struct Hash
{
    int h[3];

    Hash()
    {
        for(int i = 0; i < 3; i++)
        {
            h[i] = 0;
        }
    }

    void add_c(char c)
    {
        for(int i = 0; i < 3; i++)
        {
            h[i] = add(mul(h[i], BASE[i], MOD[i]), c, MOD[i]);
        }
    }
    void rem(char c, int len)
    {
        for(int i = 0; i < 3; i++)
        {
            int t_c = mul(c, pw[i][len - 1], MOD[i]);
            h[i] = del(h[i], t_c, MOD[i]);
        }
    }

    bool operator<(Hash other) const
    {
        return h[0] < other.h[0] || (h[0] == other.h[0] && h[1] < other.h[1]) || (h[0] == other.h[0] && h[1] == other.h[1] && h[2] < other.h[2]);
    }
    bool operator==(Hash other) const
    {
        for(int i = 0; i < 3; i++)
        {
            if(h[i] != other.h[i]) return false;
        }
        return true;
    }
};

map <Hash, int> mp;

void sol(int par)
{
    for(int i = 0; i < 3; i++)
    {
        pw[i][0] = 1;
    }
    for(int i = 1; i <= MAXN * 9; i++)
    {
        for(int j = 0; j < 3; j++)
        pw[j][i] = mul(pw[j][i - 1], BASE[j], MOD[j]);
    }
    Hash temp = Hash();
    int len = 0;
    for(int i = 0; i < n; i++)
    {
        if(i >= k)
        {
            int num = a[i - k];
            do
            {
                int nb = num % 10;
                temp.rem(nb, len);
                len--;
                num /= 10;
            }
            while(num);

            temp.rem(10, len);
            len--;
        }
        int num = a[i];
        do
        {
            int nb = num % 10;
            temp.add_c(nb);
            len++;
            num /= 10;
        }
        while(num);

        len++;
        temp.add_c(10);
        //printf("%d %d\n", temp.h[0], temp.h[1]);
        if(i >= k - 1)
        {
            mp[temp]++;
        }
    }

    temp = Hash();
    int sz = 0;
    len = 0;
    long long ans = 0;
    for(int i = 0; i < m; i++)
    {
        if(par == 2 && i > 0 && b[i] != b[i - 1])
        {
            temp = Hash();
            len = 0;
            sz = 0;
        }
        else if(par == 1 && i > 0 && b[i] <= b[i - 1])
        {
            temp = Hash();
            sz = 0;
            len = 0;
        }

        if(sz >= k)
        {
            int num = b[i - k];
            do
            {
                int nb = num % 10;
                temp.rem(nb, len);
                len--;
                num /= 10;
            }
            while(num);
            sz--;
            temp.rem(10, len);
            len--;
        }

        int num = b[i];
        do
        {
            int nb = num % 10;
            temp.add_c(nb);
            len++;
            num /= 10;
        }
        while(num);

        len++;
        temp.add_c(10);
        sz++;

        //printf("~%d %d\n", i, sz);
        if(sz == k)
        {
            //printf("%d %d\n", i - k + 1, i);
            ans += mp[temp];
        }
    }
    printf("%lld\n", ans);
}

void solve()
{
    if(w == 2)
    {
        sol(2);
    }
    else
    {
        sol(1);
    }
}

int main()
{
    read_input();
    solve();

    return 0;
}

/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
*/

/*
1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/

/*
2 4
12
1 1 3 3 3 3 3 2 2 2 2 2
10
3 3 3 3 2 3 2 2 2 2
*/
