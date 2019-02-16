#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, a = 0, last = 0, current = 0, trees = 0;
    cin >> n;
    int m[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(last == 0)
        {
            m[i] = 0;
        }
        else if(last < a)
        {
            m[i] = 1;
            if(m[i - 1] == 0 || m[i - 1] == -1)
            {
                current = 0;
            }
            current++;
        }
        else if(last > a)
        {
            m[i] = 0;
            current++;
        }
        else if(last == a)
        {
            m[i] = -1;
            current = 0;
        }
        last = a;
        if(current > trees) trees = current;
    }
    cout << trees + 1;
}
