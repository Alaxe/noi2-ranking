#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int N, K;
    cin >> N >> K;

    int FIRST, MUL, ADD, MOD;
    cin >> FIRST >> MUL >> ADD >> MOD;

    vector<int> vecStories;

    vecStories.push_back(FIRST);

    for (int i = 0; i < N; i++)
        vecStories.push_back((vecStories[i]*MUL + ADD)%MOD);

    unsigned long long nTotal = 0;

    for (int i = 0; i < N; i++)
    {
        /*
        int nDaysFun = 0;

        for (int j = i; j < K; j++)
            if (vecStories[i] >= vecStories[j])
                nDaysFun++;
            else
                break;

        nTotal += vecStories[i];
        nTotal += vecStories[i]*nDaysFun;
        i += nDaysFun;

        if (nDaysFun == K)
        {
        */
            int nMax = vecStories[i];
            for (int x = max(i-K+1, 0); x <= i; x++)
                if (vecStories[x] > nMax)
                    nMax = vecStories[x];

            nTotal += nMax;
        //}
    }

    cout << nTotal << endl;

    return 420;
}
