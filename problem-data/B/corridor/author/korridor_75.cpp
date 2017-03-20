#include <cstdio>
#include <vector>

#define pii pair<int, int>

using namespace std;
int w, h; // 1..1*10^9
int n;    // 1..200 000
vector<int> v;
int main ()
{
    pii pOld, pNew;
    scanf("%d%d", &w, &h);
    v.resize(h+1);
    scanf("%d", &n);
    scanf("%d%d", &pOld.first, &pOld.second);

    for (int i = 1;  i < n; i++)
    {
        scanf("%d%d", &pNew.first, &pNew.second);
        if (pNew.first == pOld.first) // it is vertical
        {
            int y1 = pNew.second;
            int y2 = pOld.second;
            if (y1 > y2)
                swap(y1, y2);
            for (int j = y1; j < y2; j++)
                if (v[j] < pNew.first)
                    v[j] = pNew.first;
        }
        pOld = pNew;
    }
    long long cleaned = 0;
    long long area = ((long long) w) * h;
    for (int i = 0; i < v.size(); i++)
        cleaned += v[i];
    printf("%lld\n", area - cleaned);
    return 0;
}

