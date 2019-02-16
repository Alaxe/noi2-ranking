#include <iostream>
#include <stack>

using namespace std;

int n, a[100005], k[5];

stack <int> r[5][100005];

bool b;

int R;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    k[1] = 1;
    k[2] = 1;
    k[3] = 1;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    r[1][0].push(a[0]);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < k[1]; j++)
        {
            if(r[1][j].top() < a[i])
            {
                r[1][j].push(a[i]);
            }
            else
            {
                b = true;
            }
        }
        if(b)
        {
            r[1][k[1]].push(a[i]);
            k[1]++;
            b = false;
        }
    }

    r[2][0].push(a[0]);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < k[2]; j++)
        {
            if(r[2][j].top() > a[i])
            {
                r[2][j].push(a[i]);
            }
            else
            {
                b = true;
            }
        }
        if(b)
        {
            r[2][k[2]].push(a[i]);
            k[2]++;
            b = false;
        }
    }

    r[3][0].push(a[0]);
    for(int i = 1, l; i < n; i++)
    {
        for(int j = 0; j < k[3]; j++)
        {
            if(r[3][j].top() > a[i])
            {
                if(r[3][j].size() == 1)
                {
                    b = true;
                }
                else
                {
                    r[3][j].push(a[i]);
                }
            }
            else if(r[3][j].top() < a[i])
            {
                if(r[3][j].size() == 1)
                {
                    r[3][j].push(a[i]);
                }
                else
                {
                    l = r[3][j].top();
                    r[3][j].pop();
                    if(l > r[3][j].top())
                    {
                        r[3][j].push(l);
                        r[3][j].push(a[i]);
                    }
                    else
                    {
                        r[3][j].push(l);
                        b = true;
                    }
                }
            }
            else
            {
                b = true;
            }
        }

        if(b)
        {
            r[3][k[3]].push(a[i]);
            k[3]++;
            b = false;
        }
    }

    for(int i = 0; i < k[1]; i++)
    {
        if(R < r[1][i].size())
        {
            {
                R = r[1][i].size();
            }
        }
    }

    for(int i = 0; i < k[2]; i++)
    {
        if(R < r[2][i].size())
        {
            R = r[2][i].size();
        }
    }

    for(int i = 0, l; i < k[3]; i++)
    {
        if(r[3][i].size() > 1){
            l = r[3][i].top();
            r[3][i].pop();
            if(l < r[3][i].top())
            {
                if(R < r[3][i].size() + 1)
                {
                    R = r[3][i].size() + 1;
                }
            }
        }
    }

    cout << R << "\n";

    return 0;
}


