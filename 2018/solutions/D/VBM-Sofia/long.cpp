#include <iostream>

using namespace std;

long long stringToLongLong(string str)
{
    long long tmp = 0, step = 1;
    for (int i = str.size() - 1; i >= 0; i --)
    {
        tmp = tmp + (str[i] - '0') * step;
        step *= 10;
    }
    return tmp;
}

long long makeZeros(long long tmp)
{
    long long curr = 1;
    for (int i = 0; i < tmp - 1; i ++)
    {
        curr *= 10;
    }
    return curr;
}

bool IsIt10n(long long a)
{
    while (1)
    {
        if (a % 10 == 0)
        {
             a /= 10;
        }
        else if (a > 1)
        {
            return 0;
        }
        else if (a == 1)
        {
            return 1;
        }
    }
}

int HowManyDigits(long long a)
{
    int i = 0;
    while (a > 0)
    {
        a /= 10;
        i ++;
    }
    return i;
}

int main()
{
    long long k, ost, Nmb, n2, smt;
    string n;

    cin >> n >> k;
        string g = "1";
        for (int i = 0; i < stringToLongLong(n) - 1; i ++)
        {
            g = g + "0";
        }
        //cout << IsIt10n(k) << endl;
        if (IsIt10n(k))
        {
            cout << g << endl;
        }
        else
        {
            string curr = "1";
            for (int i = 0; i < HowManyDigits(k); i ++)
            {
                curr = curr + "0";
            }
            //cout << curr << endl;
            smt = stringToLongLong(curr);
            for (int i = HowManyDigits(k); i < stringToLongLong(n); i ++)
            {
                Nmb = smt / k;
                smt = smt - (Nmb * k);
                smt *= 10;
            }
            cout << k - (smt / 10) + stringToLongLong(g) << endl;
        }
    return 0;
}
