#include <bits/stdc++.h>
using namespace std;

#define MAX 200111

int n, a, b, d[MAX], d1[MAX], ans;
vector <int > gr[MAX];
bool used[MAX];

void tr(int a, int b, int dist)
{
    //cout << a+1 << b+1 << " " <<dist<< endl;
    if(a == b)
    {
        ans = max(dist - 1, ans);
        return;
    }
    for(int i = 0; i < gr[a].size(); i++)
    {
        if(used[gr[a][i]] == false)
        {
            for(int j = 0; j < gr[b].size(); j++)
            {
                if(used[gr[b][j]] == false)
                {used[gr[b][j]] = true;
                used[gr[a][i]] = true;
                    tr(gr[a][i],gr[b][j], dist + 1);
                    used[gr[b][j]] = false;
    used[gr[a][i]] = false;
                }
            }
        }
    }
    ans = max(dist, ans);

    return;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n - 1;i++)
    {
        cin >> a >> b;
        a--;
        b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    cin >> a >> b;
    a--;
    b--;
    used[a] = used[b] = true;
    tr(a, b, 0);
    cout << ans + 1<< endl;
    return 0;
}
/*

6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

*/
