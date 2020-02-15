#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, u, v, i, V=0, max = 0, j, br = 1;
    int a[105], b[105]={0};
    cin >> n >> u >> v;
    for (i = 0; i < n; i++)cin >> a[i];
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
            if (a[j] > a[i])b[i]++;

    for (i = 0; i < n-1; i++)
    {
        if (a[i]<=a[i+1])V = V+u*v*a[i];
        else
        {

            if (b[i] > 0)max = a[i];
            else max = a[i+1];
            br=1;

            for (j = i+1; j < n; j++)
            {
                if (a[j]>a[i])break;
                else if (b[j] == 0){max = a[j]; break;}
                else br++;
            }

            i+=br-1;
            V += max*(u*br)*v;
        }
    }
    cout << V << endl;

    return 0;
}
/*
5 1 1
2 4 8 5 7
-----------
20
*/
