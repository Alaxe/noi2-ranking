#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdio.h>
#define X first
#define Y second

#define _ << " " <<
#define debug(x) #x << " = " << x

#define ll long long
#define ull unsigned long long

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using bi = std::string;
#define int long long

inline int gc(const char& c) noexcept
{
    if (c <= '9')
        return c - '0';
    else
        return 10 + c - 'A';
}

inline char toc(const int& i) noexcept
{
    if (i <= 9)
        return '0' + i;
    else
        return 'A' + i - 10;
}

bi add(const bi& a, const bi& b, int m)
{
    bi result;
    int carry = 0;

    int i = a.length() - 1, j = b.length() - 1;

    int t;
    char c;
    while(i >= 0 && j >= 0)
    {
        t = carry + gc(a[i]) + gc(b[j]);

        if (t >= m) carry = 1, c = toc(t - m);
        else carry = 0, c = toc(t);

        result.push_back(c);
        --i; --j;
    }

    for (; i >= 0; i--)
    {
        t = carry + gc(a[i]);
        if (t >= m) carry = 1, c = toc(t - m);
        else carry = 0, c = toc(t);

        result.push_back(c);
    }

    for (; j >= 0; j--)
    {
        t = carry + gc(b[j]);
        if (t >= m) carry = 1, c = toc(t - m);
        else carry = 0, c = toc(t);

        result.push_back(c);
    }

    if (carry)
        result.push_back(toc(carry));

    std::reverse(result.begin(), result.end());
    return result;
}

int divrm(const bi& a, int m, int b)
{
    int t = 0;
    for (int i = 0; i < (int)a.length(); i++)
        t = (t * b + gc(a[i])) % m;

    return t;
}

inline void push(bi& r, char x)
{
    if (x == '0' && r.empty())
        return;
    r.push_back(x);
}

bi sub(const bi& a, const bi& b, int m)
{
    bi result;
    int carry = 0;

    int i = a.length() - 1, j = b.length() - 1;

    int t;
    char c;
    while(i >= 0 && j >= 0)
    {
        t = carry + gc(a[i]) - gc(b[j]);

        if (t < 0) carry = -1, c = toc(t + m);
        else carry = 0, c = toc(t);

        result.push_back(c);
        --i; --j;
    }

    for (; i >= 0; i--)
    {
        t = carry + gc(a[i]);
        if (t < 0) carry = -1, c = toc(t + m);
        else carry = 0, c = toc(t);

        result.push_back(c);
    }

    while(result.size() && result.back() == '0') result.pop_back();
    std::reverse(result.begin(), result.end());
    return result;
}

bi div(const bi& a, int b)
{
    bi result;

    int cur = 0;
    int i = 0, n = a.length();

    bool has_to = false;
    do
    {
        has_to = false;
        while(i < n && cur < b - 1)
            cur = cur * b + gc(a[i++]), push(result, '0');

        push(result, toc(cur / (b - 1)));
        cur %= b - 1;
        if (i < n)
        {
            cur = cur * b + gc(a[i++]);
            has_to = true;
        }

    } while(i < n);

    if (has_to)
        push(result, toc(cur / (b - 1)));

    return result;
}


#undef int
int main()
#define int long long
{
    std::ios::sync_with_stdio(false);

    int b;
    std::cin >> b;

    bi m;
    int q = 4;
    while(q--)
    {
        std::cin >> m;

        if (divrm(m, b - 1, b) != 0)
        {
            std::cout << 0 << std::endl;
            continue;
        }

        const int base = m.length();

        std::string bl[b];
        for (int i = 1; i < b; i++)
        {
            bl[i] = toc(i);
            for (int j = 0; j < base - 1; j++)
                bl[i] += '0';
        }

   //     std::cout << base << std::endl;
        for (int l = base; l <= base + 10; l++)
        {
            for (int k = 1; k < b; k++)
            {
                bl[k] += '0';

              //  std::cout << debug(k) _ debug(l) _ debug(bl[k]) << std::endl;
                bi above = add(m, bl[k], b);

                std::string kk;
                kk += toc(k);

                above = sub(above, kk, b);
                bi x = div(above, b);

                if ((int)x.length() == l && x[0] - '0' == k)
                {
                    std::cout << x << std::endl;
                    goto heaven;
                }
            }
        }
        std::cout << 0 << std::endl;
        heaven:;
    }
    return 0;
}
