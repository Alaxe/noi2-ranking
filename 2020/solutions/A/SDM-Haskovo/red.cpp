#include<iostream>
#include<random>
#include<map>
#include<time.h>

using namespace std;

mt19937 rnd(22);

const int MAXN = 1e5 + 5;
const int MAXA = 2e6 + 5;

int n, m;
int a[MAXN], b[MAXN];

pair <long long, long long> code[MAXA];
pair <long long, long long> prefix[2][MAXN];

int canContinue[2][MAXN];
map <pair <long long, long long>, int> mp;

void Init()
{
    for(int i = 0;i<MAXA;i++)
    {
        code[i] = {rnd(), rnd()};
    }

    prefix[0][0] = {code[ a[0] ].first, code[ a[0] ].second};
    for(int i = 1;i<n;i++)
    {
        prefix[0][i].first = (prefix[0][i-1].first+code[ a[i] ].first);
        prefix[0][i].second = (prefix[0][i-1].second+code[ a[i] ].second);
    }

    prefix[1][0] = {code[ b[0] ].first, code[ b[0] ].second};
    for(int i = 1;i<m;i++)
    {
        prefix[1][i].first = (prefix[1][i-1].first+code[ b[i] ].first);
        prefix[1][i].second = (prefix[1][i-1].second+code[ b[i] ].second);
    }
}

pair <long long, long long> getPrefix(int l, int r, int arr)
{
    if(l==0) return prefix[arr][r];
    return {prefix[arr][r].first-prefix[arr][l-1].first, prefix[arr][r].second-prefix[arr][l-1].second};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long answer = 0;

    int w, k;
    cin >> w >> k;

    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin >> a[i];
    }

    cin >> m;
    for(int i = 0;i<m;i++)
    {
        cin >> b[i];
    }

    Init();
    if(w==2)
    {
        canContinue[0][n-1] = 1;
        for(int i = n-2;i>=0;i--)
        {
            if(a[i]==a[i+1]) canContinue[0][i] = canContinue[0][i+1] + 1;
            else canContinue[0][i] = 1;
        }

        canContinue[1][m-1] = 1;
        for(int i = m-2;i>=0;i--)
        {
            if(b[i]==b[i+1]) canContinue[1][i] = canContinue[1][i+1] + 1;
            else canContinue[1][i] = 1;
        }
    }
    else
    {
        canContinue[0][n-1] = 1;
        for(int i = n-2;i>=0;i--)
        {
            if(a[i]<a[i+1]) canContinue[0][i] = canContinue[0][i+1] + 1;
            else canContinue[0][i] = 1;
        }

        canContinue[1][m-1] = 1;
        for(int i = m-2;i>=0;i--)
        {
            if(b[i]<b[i+1]) canContinue[1][i] = canContinue[1][i+1] + 1;
            else canContinue[1][i] = 1;
        }
    }

    for(int i = 0;i<n;i++)
    {
        if(canContinue[0][i]>=k)
        {
            mp[getPrefix(i, i+k-1, 0)]++;
        }
    }
    for(int i = 0;i<m;i++)
    {
        if(canContinue[1][i]>=k)
        {
            answer += mp[getPrefix(i, i+k-1, 1)];
        }
    }

    cout << answer << '\n';
}
/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
