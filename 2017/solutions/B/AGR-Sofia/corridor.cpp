#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
pair<pair<long long,long long>, long long> p[100000], bin;
long long s = 0;
bool open[100000];
long long bs = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long w, h;
    long long n;
    cin >> w >> h >> n;
    pair<long long, long long> l, c;
    for(long long i = 0; i < n; i ++) {
        l = c;
        cin >> c.first >> c.second;
        if(i > 0) {
            if(l.second != c.second) {
                bin.first.second = l.first;
                bin.first.first = min(l.second, c.second);
                bin.second = bs;
                p[s++] = bin;
                bin.first.first = max(l.second, c.second);
                p[s++] = bin;
                bs ++;
            }
        }
    }
    sort(p, p + s);
    priority_queue<pair<long long, long long> > q;
    pair<long long, long long> bin2;
    unsigned long long ans = 0;
    for(long long i = 0; i < s; i ++) {
            if(i > 0) {
                ans += (p[i].first.first - p[i - 1].first.first) * (w - q.top().first);
            }
            open[p[i].second] = !open[p[i].second];
            if(open[p[i].second]) {
                bin2.first = p[i].first.second;
                bin2.second = p[i].second;
                q.push(bin2);
            }
            while(!q.empty() && !open[q.top().second])    q.pop();
    }
    cout << ans;
}
/*
15 10
17
6 0
6 2
11 2
11 4
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/

/*
10 10
22
1 0
1 2
3 2
3 1
4 1
4 3
5 3
5 5
4 5
4 4
3 4
3 3
2 3
2 7
6 7
6 5
7 5
7 9
6 9
6 8
0 8
0 10
*/
