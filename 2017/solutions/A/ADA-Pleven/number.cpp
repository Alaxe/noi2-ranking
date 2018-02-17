#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

struct longNum
{
    int BASE = 10, LEN = 210;
    vector<int> v;
    longNum()
    {
        v.resize(LEN);
    }
    longNum(string s)
    {
        v.resize(LEN);
        for (int i = 0; i < s.size(); i++)
            v[i] = (int)(s[s.size()-i-1]-'0');
    }
    void operator= (longNum f)
    {
        for (int i = 0; i < LEN; i++)
            v[i] = f.v[i];
    }
    longNum operator+ (longNum f)
    {
        longNum ret;
        for (int i = 0; i < LEN; i++)
        {
            ret.v[i] += f.v[i] + v[i];
            if (ret.v[i] >= BASE)
            {
                ret.v[i] %= BASE;
                ret.v[i+1]++;
            }
        }
        return ret;
    }
    longNum operator<< (int f)
    {
        longNum ret = *this;
        for (int i = LEN - 1; i >= f; i--)
            ret.v[i] = ret.v[i-f];
        for(int i = f - 1; i >= 0; i--)
            ret.v[i] = 0;
        return ret;
    }
    longNum operator* (int f)
    {
        longNum ret = *this;
        int over = 0;
        for (int i = 0; i < LEN; i++)
        {
            ret.v[i] = ret.v[i]*f + over;
            over = ret.v[i] / BASE;
            ret.v[i] %= BASE;
        }
        return ret;
    }
    longNum operator* (longNum f)
    {
        longNum ret = f*v[0];
        for (int i = 1;  i < LEN; i++)
        {
            if (v[i] == 0)
                continue;
            ret = ret + ((f*v[i])<<i);
        }
        return ret;
    }
    longNum operator+ (int f)
    {
        longNum ret = *this;
        ret.v[0] += f;
        for (int i = 0; ret.v[i] >= BASE; i++)
        {
            ret.v[i+1] += ret.v[i] / BASE;
            ret.v[i] %= BASE;
        }
        return ret;
    }
    longNum operator/ (int f)
    {
        longNum ret = *this;
        for (int i = LEN - 1; i >= 0; i--)
        {
            if (i != 0)
                ret.v[i-1] += (ret.v[i] % f) * BASE;
            ret.v[i] /= f;
        }
        return ret;
    }
    bool operator== (longNum f)
    {
        for (int i = 0; i < LEN; i++)
            if (v[i] != f.v[i])
                return false;
        return true;
    }

    bool operator!= (longNum f)
    {
        return !(*this == f);
    }
    bool operator> (longNum f)
    {
        for (int i = LEN-1; i >= 0; i--)
        {
            if (v[i] > f.v[i])
                return true;
            if (v[i] < f.v[i])
                return false;
        }
        return false;
    }
    longNum operator- (longNum f)
    {
        longNum ret = *this;
        for (int i = 0; i < LEN; i++)
        {
            ret.v[i] -= f.v[i];
            if (ret.v[i] < 0)
            {
                ret.v[i] += BASE;
                ret.v[i+1]--;
            }
        }
        return ret;
    }
    void print()
    {
        bool print = false;
        for (int i = LEN - 1; i >= 0; i--)
        {
            if (v[i] > 0)
                print = true;
            if (print)
                printf("%d", v[i]);
        }
        if (!print)
            printf("0");
        printf("\n");
    }
};

long long a, b;
int ans;

longNum findFirst(longNum z)
{
    longNum l, r = z;
    for (;l + 1 != r;)
    {
        longNum mid = (r + l) / 2;
        if (mid * (mid + 1) > z)
            r = mid;
        else
            l = mid;
    }
    return l;
}
int main ()
{
    string aS, bS;
    cin >> aS >> bS;
    longNum a(aS);
    longNum b(bS);

    longNum f = findFirst(a);
    longNum s = findFirst(b);
    longNum ans = (s - f);
    if (f * (f+1) == a)
        ans = ans + 1;
    ans.print();
    return 0;
}
