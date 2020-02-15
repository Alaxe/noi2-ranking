#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5;

bool insecure_places [MAXN];

bool visited [MAXN];

int n;
vector < int > ln [MAXN];
vector < int > separated_graph [MAXN];

void compose (int a, int b)
{
    //cout << "(" << a << "," << b << ") is part of a loop." << endl;
    separated_graph [a].push_back (b);
    separated_graph [b].push_back (a);
}

void bfs (int closed_from, int closed_to)
{
    for(int i = 0 ; i < n ; i ++)
        visited [i] = false;

    queue < int > q;
    q.push (0);
    visited [0] = true;
    while (!q.empty ())
    {
        int front = q.front (); q.pop ();
        for (auto& x : ln [front])
        {
            if (not visited [x] and (!(front == closed_from and x == closed_to)) and (!(front == closed_to and x == closed_from)))
            {
                visited [x] = true;
                q.push (x);
            }
        }
    }
    for (int i = 0 ; i < n ; i ++)
        if (not visited [i])
            return;
    compose (closed_from, closed_to);
}

void input ()
{
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0 ; i < m ; i++)
    {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        ln [a].push_back (b);
        ln [b].push_back (a);
    }
}

int solve ()
{
    input ();

    for (int i = 0 ; i < n ; i ++)
        for (auto& x : ln [i])
        {
            if (i < x)
                bfs (i, x);
        }

    for(int i = 0 ; i < n ; i ++)
        visited [i] = false;
    int answer = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        if (not visited [i])
        {
            //cout << "Component of " << i << endl;
            long long vertexes = 0;
            queue < int > q;
            q.push (i);
            visited [i] = true;
            while (!q.empty ())
            {
                int front = q.front (); q.pop ();
                vertexes += (visited [front]);
                for (auto& x : separated_graph [front])
                {
                    if (not visited [x])
                    {
                        visited [x] = true;
                        q.push (x);
                    }
                }
            }
            //cout << "Contains " << (vertexes * (vertexes - 1)) / 2 << " possible pair of safe vertexes" << endl;
            answer += (vertexes * (vertexes - 1)) / 2;
        }
    }
    return answer;
}

int main ()
{
    cin.tie (nullptr);
    ios::sync_with_stdio(false);
    cout << solve () << endl;
    return 0;
}

/**
5 5
1 2
2 3
3 1
2 4
2 5


7 8
1 2
1 3
3 4
4 2
4 5
5 6
6 7
5 7
*/
