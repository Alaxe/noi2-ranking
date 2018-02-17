#include <iostream>
#include <algorithm>

using namespace std;

struct People
{
    long long P_Coming;
    long long P_Time;
};
People Nmb[720];

bool cmp(People lhs, People rhs)
{
    return lhs.P_Coming < rhs.P_Coming;
}

int main()
{
    long long i = 0, j, nextStart = 0;

    while (cin)
    {
        cin >> Nmb[i].P_Coming >> Nmb[i].P_Time;
        i ++;
    }
    sort(Nmb, Nmb + i, cmp);
    for (j = 0; j < i; j ++)
    {
        nextStart = max(nextStart, Nmb[j].P_Coming);
        nextStart += Nmb[j].P_Time;
        if (j == i - 1)
        {
            cout << nextStart - Nmb[j].P_Coming << endl;
        }
    }
    return 0;
}
