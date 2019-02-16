#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_N = 5004;
vector<int> iskam[MAX_N];
int par[MAX_N], kap;
bool shefLiE[MAX_N];
bool geiLiE[MAX_N];

struct Person
{
    int n, jelani, rang;
    long long cash;

    bool operator <(Person r) const
    {
        if(kap == 0)
        {
            ++ kap;
            return !(jelani <= r.jelani);
        }
        return !(rang <= r.rang);
    }
};
Person p[MAX_N];

void unite(int x, int y)
{
    par[y] = x;
    ++ p[x].rang;
}

bool contains(vector<int> v, int k)
{
    for(int i = 0 ; i < v.size() ; ++ i)
    {
        if(v[i] == k)
            return true;
    }
    return false;
}

int main()
{
    int n, zaplata;
    cin >> n >> zaplata;
    for(int i = 0 ; i < n ; ++ i)
    {
        par[i] = i;
        p[i].rang = 0;
    }
    for(int i = 0 ; i < n ; ++ i)
    {
        int k;
        cin >> k;
        p[i].n = i;
        for(int j = 0 ; j < k ; ++ j)
        {
            int t;
            cin >> t;
            iskam[i].push_back(t - 1);
            ++ p[t - 1].jelani;
        }
    }
    sort(p, p + n);
    for(int i = n - 1 ; i >= 0; -- i)
    {
        for(int j = n - 1 ; j >=  0 ; -- j)
        {
            if(i == j)
            {
                continue;
            }
            if(shefLiE[p[j].n] || geiLiE[p[j].n])
            {
                continue;
            }
            if(contains(iskam[j], i))
            {
                unite(p[i].n, p[j].n);
                shefLiE[p[i].n] = 1;
                geiLiE[p[j].n] = 1;
            }
        }
    }
    sort(p, p + n);
    long long gloMax = 0;
    for(int i = n - 1 ; i >= 0 ; -- i)
    {
        if(p[i].rang == 0)
        {
            p[i].cash = zaplata;
            gloMax += p[i].cash;
        }
        else
        {
            int koef = 0;
            for(int j = 0 ; j < n; ++ j)
            {
                if(i == j)
                {
                    continue;
                }
                if(par[j] == p[i].n)
                {
                    koef = p[j].cash;
                    p[i].cash += p[j].cash;
                }
            }
            p[i].cash += zaplata;
            gloMax += p[i].cash;
        }
    }
    cout << gloMax<< '\n';
    return 0;
}
