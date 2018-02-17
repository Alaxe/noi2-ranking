#include <iostream>

using namespace std;

int main()
{
    long long months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string str1, str2, str3, str4;
    long long d1 = 0, m1 = 0, d2 = 0, m2 = 0, d3 = 0, m3 = 0, d4 = 0, m4 = 0, i, k = 1;
    long long s1, s2, s3, s4, days = 0, j, period = 0;
    bool stop = 0;

    cin >> str1 >> str2 >> str3 >> str4;
    k = 1;
    for (i = str1.size() - 1; i >= 0; i --)
    {
        if (str1[i] == '/')
        {
            s1 = i - 1;
            break;
        }
        m1 += (str1[i] - '0') * k;
        k *= 10;
    }
    k = 1;
    for (i = str2.size() - 1; i >= 0; i --)
    {
        if (str2[i] == '/')
        {
            s2 = i - 1;
            break;
        }
        m2 += (str2[i] - '0') * k;
        k *= 10;
    }
    k = 1;
    for (i = str3.size() - 1; i >= 0; i --)
    {
        if (str3[i] == '/')
        {
            s3 = i - 1;
            break;
        }
        m3 += (str3[i] - '0') * k;
        k *= 10;
    }
    k = 1;
    for (i = str4.size() - 1; i >= 0; i --)
    {
        if (str4[i] == '/')
        {
            s4 = i - 1;
            break;
        }
        m4 += (str4[i] - '0') * k;
        k *= 10;
    }



    k = 1;
    for (i = s1; i >= 0; i --)
    {
        d1 += (str1[i] - '0') * k;
        k *= 10;
    }
    k = 1;
    for (i = s2; i >= 0; i --)
    {
        d2 += (str2[i] - '0') * k;
        k *= 10;
    }
    k = 1;
    for (i = s3; i >= 0; i --)
    {
        d3 += (str3[i] - '0') * k;
        k *= 10;
    }
    k = 1;
    for (i = s4; i >= 0; i --)
    {
        d4 += (str4[i] - '0') * k;
        k *= 10;
    }
    for (i = 0; i < m1 - 1; i ++)
    {
        days += months[i];
    }
    days += d1;
    d1 = days - (days / 23) * 23;
    if (d1 == 0)
    {
        d1 = 23;
    }
    days = 0;
    for (i = 0; i < m2 - 1; i ++)
    {
        days += months[i];
    }
    days += d2;
    d2 = days - (days / 28) * 28;
    if (d2 == 0)
    {
        d2 = 28;
    }
    days = 0;
    for (i = 0; i < m3 - 1; i ++)
    {
        days += months[i];
    }
    days += d3;
    d3 = days - (days / 33) * 33;
    if (d1 == 0)
    {
        d3 = 33;
    }
    i = d1;
    j = d2;
    k = d3;
    while (stop != 1)
    {
        k += 33;
        while (j <= k)
        {
            j += 28;
        }
        if (j > k)
        {
            j -= 28;
        }
        while (i <= k)
        {
            i += 23;
        }
        if (i > k)
        {
            i -= 23;
        }
        if (i == k && j == k)
        {
            period = k;
            break;
        }
    }
    days = 0;
    for (i = 0; i < m4 - 1; i ++)
    {
        days += months[i];
    }
    days += d4;
    if (period == days)
    {
        cout << period << endl;
    }
    if (days > period)
    {
        cout << days + (period - (days % period));
    }
    return 0;
}
