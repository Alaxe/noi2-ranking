///like and subscribe bili220022 in twitch

#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>

using namespace std;

const int MAXN = 1e5;
const int MAXM = 1e5;
int w, k;
int n, m;
int a[MAXN+100], b[MAXM+100];
int ans;

void input()
{
    cin>>w>>k;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for (int i=0; i<m; i++)
    {
        cin>>b[i];
    }
}

void output()
{
    cout<<ans<<endl;
}

void calcA2(unordered_map<int, int> &d)
{
    int curr = -1;
    int counter = 0;

    for (int i=0; i<n; i++)
    {
        if (curr == a[i])
            counter++;
        else
        {
            if (counter >= k)
                d[curr] += counter-k + 1;
            curr = a[i];
            counter = 1;
        }
    }
    if (counter >= k)
        d[curr] += counter-k + 1;
}

void calcB2(unordered_map<int, int> &d)
{
    int curr = -1;
    int counter = 0;

    for (int i=0; i<m; i++)
    {
        if (curr == b[i])
            counter++;
        else
        {
            if (counter >= k)
                ans += d[curr]*(counter-k +1);
            curr = b[i];
            counter = 1;
        }
    }
    if (counter >= k)
        ans += d[curr]*(counter-k +1);
}

void calcA1(map<queue<int>, int> &d)
{
    int counter = 0;
    queue<int> q;

    for (int i=0; i<n; i++)
    {
        if (a[i-1] < a[i])
        {
            counter++;
            q.push(a[i]);
            if (counter == k)
            {
                d[q]++;
                q.pop();
                counter--;
            }
        }
        else
        {
            while(!q.empty()) q.pop();
            q.push(a[i]);
            counter = 1;
        }
    }
}

void calcB1(map<queue<int>, int> &d)
{
    int counter = 0;
    queue<int> q;

    for (int i=0; i<m; i++)
    {
        if (b[i-1] < b[i])
        {
            counter++;
            q.push(b[i]);
            if (counter == k)
            {
                ans += d[q];
                q.pop();
                counter--;
            }
        }
        else
        {
            while(!q.empty()) q.pop();
            q.push(b[i]);
            counter = 1;
        }
    }
}

void solve()
{
    if (w == 2)
    {
        unordered_map<int, int> d;
        calcA2(d);
        ans = 0;
        calcB2(d);
    }
    else
    {
        map<queue<int>, int> d;
        calcA1(d);
        ans = 0;
        calcB1(d);
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    output();
    return 0;
}

/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

2 2
3
3 3 3
7
3 3 2 3 3 3 5 5

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7

1 3
7
1 3 3 7 8 9 12
11
1 7 3 7 8 9 1 3 3 7 8
*/
