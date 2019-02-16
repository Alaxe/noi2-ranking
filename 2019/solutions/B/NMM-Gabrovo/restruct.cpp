#include<bits/stdc++.h>
using namespace std;

const int MAXN=5002;
int n, k;
vector<int> req[MAXN];

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>k;
    int r;
    for(int i=0; i<n; ++i)
    {
        int q;
        cin>>q;
        for(int j=0; j<q; ++j)
        {
            int w;
            cin>>w;
            req[i].push_back(w);
        }
    }

    return 0;
}

/*
4 100
1 4
3 1 3 4
2 1 2
1 3
*/
