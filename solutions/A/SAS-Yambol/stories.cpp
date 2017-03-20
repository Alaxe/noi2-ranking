#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <climits>
using namespace std;
typedef long long lld;

int N, K;
int value[10000002];
int FIRST, MUL, ADD, MOD;

void Input()
{
    scanf("%d %d",&N, &K);
    scanf("%d %d %d %d", &FIRST, &MUL, &ADD, &MOD);

    value[1] = FIRST;

    for (int i=2; i<=N; i++)
    {
        value[i] = ((lld)value[i-1]*(lld)MUL + (lld)ADD) % (lld)MOD;
    }
}

pair<int, int> madeck[10000002];
int dl, dr;

int main ()
{
    Input();

    lld fin = 0;

    dl = 1;
    dr = 0;

    for (int i=1; i<=N; i++)
    {
        while (dl<=dr && madeck[dr].first <= value[i]) dr--;

        int mnday = max(1, i-K+1);
        while (dl<=dr && madeck[dl].second < mnday) dl++;

        madeck[++dr] = make_pair(value[i], i);

        int curday = madeck[dl].first;
        fin += (lld)curday;
    }

    printf("%lld\n", fin);
}
