#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

/**

upper_bound  >x
lower_bound >=x
--lower_bound <x
--upper_bound <=x

*/

vector<pair< pair<int,int> , int> > nodes;
int n;
const int maxn = 1000000;
vector<int> ch[maxn];

int num_steps[maxn];
bool checked[maxn];

const int maxx = 1000000;
int fall[maxx];
int next_free[maxx];

int ans(int i)
{
    if(i == -1) return 0;
    if(checked[i])
    {
        return num_steps[i];
    }
    if(ch[i].size() < 2)
    {
        num_steps[i] = 1;
        checked[i] = true;
        return num_steps[i];
    }
    num_steps[i] = min(ans(ch[i][0]), ans(ch[i][1])) + 1;
    checked[i] = true;
    return num_steps[i];
}

int nf(int i)
{
    if(next_free[i] == i)   return i;
    next_free[i] = nf(next_free[i]);
    return next_free[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        nodes.push_back(pair< pair<int, int>, int >(pair<int,int>(-y, x), d));
    }
    sort(nodes.begin(), nodes.end());
    set<pair<int,int> > ends;
    for(int i = 0; i < n; i ++)
    {
        /*cout << "!" << endl;
        for(auto j: ends)
        {
            cout << j.first << " " << j.second << endl;
        }
        cout << endl << endl;*/


        int left = nodes[i].first.second;
        int right = nodes[i].first.second + nodes[i].second - 1;
        auto  l = ends.lower_bound(pair<int,int>(left, 0)), r = ends.upper_bound(pair<int,int>(right, maxn));
        if(l != ends.end() && (l->first) <= ((--r)->first))
        {
            vector<set<pair<int,int> >::iterator> rem;
            //cout << "HII";
            for(;l != r;l ++)
            {
                //cout << "!!!" << l->second << endl;
                ch[l->second].push_back(i);
                rem.push_back(l);
            }
            //cout << "!!!" << r->second << endl;

            if(r->first <= right)
            {
                ch[r->second].push_back(i);
                rem.push_back(r);
            }

            for(int k = 0; k < rem.size(); k ++)
            {
                ends.erase(rem[k]);
            }
        }
        ends.insert(pair<int,int>(left - 1, i));
        ends.insert(pair<int,int>(right + 1, i));
    }
    /*for(int i = 0; i < n; i ++)
    {
        cout << i << ": ";
        for(int j = 0; j < ch[i].size(); j ++)
        {
            cout << ch[i][j] << " ";
        }
        cout << endl;
    }*/

    for(int i = 0; i < n; i ++)
    {
        ans(i);
        //cout << i << "=" << ans(i) << endl;
    }

    for(int i = 0; i < maxx; i ++)
    {
        fall[i] = -1;
        next_free[i] = i;
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = nf(nodes[i].first.second); j < nodes[i].first.second + nodes[i].second; j = nf(j))
        {
            fall[j] = i;
            next_free[j] = next_free[j + 1];
        }
    }
    /*
    for(int i = 0; i < 15; i ++)
    {
        cout << fall[i] << " ";
    }*/

    int t;
    cin >> t;
    for(int i = 0; i < t; i ++)
    {
        int x;
        cin >> x;
        cout << ans(fall[x]) << " ";
    }

}
/**
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/
