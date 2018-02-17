#include <iostream>
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int t, n, color[10][100003], number, br;
int main ()
{
    cin>>t;
    for (int ti=0; ti<t; ti++)
    {
        cin>>n;
        br=0;
        for (int i=0; i<n; i++)
        {
            cin>>number;
            color[ti][number]++;
        }

        for (int i=1; i<=n; i++)
        {
            br = max(color[ti][i], br);
        }

        cout<<br+1<<endl;
    }
}
/*
2
4
4 1 2 3
5
4 1 2 3 4
*/
