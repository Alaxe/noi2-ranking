#include <iostream>
#include <math.h>

using namespace std;

string tostr(int nmb)
{
    string ans = "";
    while(nmb > 0)
    {
        char temp = (nmb % 10) + '0';
        nmb /= 10;
        ans = temp + ans;
    }
    return ans;
}

int fin(int nmb)
{
    int a = 1;
    while(nmb > 10)
    {
        a ++;
        nmb /= 10;
    }
    return a;
}

int main()
{
    long long a, ost, n;
    cin >> n >> a;
    ost = (long long)(pow(10, fin(a)) - a) % a;
    for(long long i = fin(a) + 1; i < n; i ++)
    {
        ost *= 10;
        ost = ost % a;
    }
    string str = tostr(a - ost);
    long long siz = str.size();
    string ans = "1";

    if(ost == 0)
        siz = n - 1;
    else
        siz = n - siz - 1;
    for(long long i = 0; i < siz; i ++)
    {
        ans = ans + "0";
    }
    if(ost != 0)
        ans = ans + str;
    cout << ans;
    return 0;
}
