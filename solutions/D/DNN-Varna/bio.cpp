#include <iostream>
using namespace std;
long long d1, m1, d2, m2, d3, m3, d4, m4;
long long days_in_month[13];

void input()
{
    string s1, s2, s3, s4;
    d1 = 0;
    m1 = 0;
    d2 = 0;
    m2 = 0;
    d3 = 0;
    m3 = 0;
    d4 = 0;
    m4 = 0;
    long long k;
    cin >> s1 >> s2 >> s3 >> s4;

    k = s1.find('/');

    for(int i = 0; i < k; i++)
    {
        d1 *= 10;
        d1 += (s1[i] - '0');
    }

    for(int i = k + 1; i < s1.size(); i++)
    {
        m1 *= 10;
        m1 += (s1[i] - '0');
    }

    k = s2.find('/');

    for(int i = 0; i < k; i++)
    {
        d2 *= 10;
        d2 += (s2[i] - '0');
    }

    for(int i = k + 1; i < s2.size(); i++)
    {
        m2 *= 10;
        m2 += (s2[i] - '0');
    }

    k = s3.find('/');

    for(int i = 0; i < k; i++)
    {
        d3 *= 10;
        d3 += (s3[i] - '0');
    }

    for(int i = k + 1; i < s3.size(); i++)
    {
        m3 *= 10;
        m3 += (s3[i] - '0');
    }

    k = s4.find('/');

    for(int i = 0; i < k; i++)
    {
        d4 *= 10;
        d4 += (s4[i] - '0');
    }

    for(int i = k + 1; i < s4.size(); i++)
    {
        m4 *= 10;
        m4 += (s4[i] - '0');
    }

}

void init()
{
    days_in_month[0] = 0;
    days_in_month[1] = 31;
    days_in_month[2] = 28 + days_in_month[1];
    days_in_month[3] = 31 + days_in_month[2];
    days_in_month[4] = 30 + days_in_month[3];
    days_in_month[5] = 31 + days_in_month[4];
    days_in_month[6] = 30 + days_in_month[5];
    days_in_month[7] = 31 + days_in_month[6];
    days_in_month[8] = 31 + days_in_month[7];
    days_in_month[9] = 30 + days_in_month[8];
    days_in_month[10] = 31 + days_in_month[9];
    days_in_month[11] = 30 + days_in_month[10];
    days_in_month[12] = 31 + days_in_month[11];
}

int main()
{
    long long max1;
    input();
    init();

    d1 += days_in_month[m1 - 1];
    d2 += days_in_month[m2 - 1];
    d3 += days_in_month[m3 - 1];
    d4 += days_in_month[m4 - 1];

    d1 %= 23;
    d2 %= 28;
    d3 %= 33;

    for(int i = 1; i < 13; i++)
        max1 += days_in_month[i];

    for(int i = d4 + 1; i; i++)
    {
        if(((i - d1) % 23 == 0 && (i - d2) % 28 == 0) && (i - d3) % 33 == 0)
        {
            cout << i - d4 << endl;
            return 0;
        }
    }

}
