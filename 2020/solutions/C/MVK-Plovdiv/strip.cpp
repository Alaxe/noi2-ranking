#include<bits/stdc++.h>
using namespace std;

long long table[50][50];
int n, k;

bool check(int i, int j)
{
    if(i < 0 || j < 0 || i > n-1 || j > n-1)
        return false;
    else
        return true;
}

int main()
{

    cin >> n >> k;
    table[0][k-1] = 1;
    if(check(1, k-2))
        table[1][k-2] = 1;
    if(check(1, k))
        table[1][k] = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(table[i][j]==0)
                continue;
            if(j < k-1)
            {
                if(check(i+1, i+j+1))
                    table[i+1][i+j+1] += table[i][j];
                if(check(i+1, j-1))
                    table[i+1][j-1] += table[i][j];
            }
            else if(j > k-1)
            {
                if(check(i+1, j+1))
                    table[i+1][j+1] += table[i][j];
                if(check(i+1, j-i-1))
                    table[i+1][j-i-1] += table[i][j];
            }
        }
    }
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << table[n-1][0] + table[n-1][n-1] << endl;

    return 0;
}

