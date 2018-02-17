#include<iostream>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;
pair<int,int> p[1000];
int n;
int gcds[200][200];
int calc_gcd(int a, int b)
{
    if(gcds[a][b] != 0)  return gcds[a][b];
    if(gcds[b][a] != 0)  return gcds[b][a];
    gcds[a][b] = __gcd(a,b);
    return gcds[a][b];
};
pair<int,int> slope(pair<int,int> a)
{
    if(a.first == 0)    return pair<int,int>(0,1);
    if(a.second == 0)    return pair<int,int>(1,0);
    bool odd = false;
    if(a.first < 0)
    {
        a.first *= -1;
        odd ^= 1;
    }
    if(a.second < 0)
    {
        a.second *= -1;
        odd ^= 1;
    }
    int gcd = calc_gcd(a.first, a.second);
    pair<int,int> ans(a.first / gcd, a.second/gcd);
    if(odd) ans.first *= -1;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> p[i].first >> p[i].second;
    }
    int ans = 0;
    for(int i = 0; i < n; i ++)
    {
        map<pair<int,int>, int> lines;
        for(int j = i + 1; j < n; j ++)
        {
            if(i != j)
            {
                pair<int,int> s = slope(pair<int,int>(p[j].first - p[i].first, p[j].second - p[i].second));
                if(lines.count(s) == 0) lines[s] = 1;
                else    lines[s] += 1;
                ans = max(ans, lines[s]);
            }
        }
        /*for(map<pair<int,int>, int>::iterator j = lines.begin(); j != lines.end(); j ++)
        {
            if(j->second > ans) ans = j->second;
        }*/
    }
    cout << ans + 1;
    //cout << endl << 1.0 * clock() / CLOCKS_PER_SEC;
}
/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/
