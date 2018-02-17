#include<bits/stdc++.h>
const long long MOD=1000000007;
const int MAXN=11005;

using namespace std;
int n;

vector<pair<pair<int, int>, pair<int, int> > > v;

bool cmp( pair<pair<int, int>, pair<int, int> > a, pair<pair<int, int>, pair<int, int> > b)
{
    return (a.second.first-a.first.first)*(a.second.second-a.first.second)<(b.second.first-b.first.first)*(b.second.second-b.first.second);
}

long long dp[MAXN];

vector<int> G[MAXN];
void mainp()
{
    int a, b;
    scanf("%d%d",&a,&b);
    v.push_back(make_pair(make_pair(0, 0), make_pair(a, b)));

    cin>>n;

    for(int i=0; i<n; i++)
    {
        int a1, b1, c1, d1;
        scanf("%d%d%d%d",&a1,&b1,&c1,&d1);
        v.push_back(make_pair(make_pair(a1, b1), make_pair(a1+c1, b1+d1)));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<v.size(); i++) dp[i]=(v[i].second.first-v[i].first.first)*(v[i].second.second-v[i].first.second);

    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            if(v[i].first.first<v[j].first.first&&
               v[i].first.second<v[j].first.second&&
               v[i].second.first>v[j].second.first&&
               v[i].second.second>v[j].second.second)
                   dp[i]-=dp[j];

        }
    }

    int m;
    scanf("%d",&m);

    for(int i=0; i<m; i++)
    {
        int a1, b1;
        scanf("%d%d",&a1,&b1);
        for(int j=0; j<v.size(); j++)
        {
            if(v[j].first.first<a1&&
            v[j].first.second<b1&&
            v[j].second.first>a1&&
            v[j].second.second>b1) {printf("%lld\n",dp[j]); break;}
        }
    }
}

int main()
{
    mainp();
    return 0;
}

/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3
*/
