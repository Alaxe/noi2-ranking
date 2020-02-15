#include <iostream>
using namespace std;
#define MAX_N 100002
int a[MAX_N];

int main()
{
    int n;
    cin >>n;
    int p;
    for(int i=0; i<n; i++)
    {
       cin >> p;
       a[p]++;
    }

    for(int i=1; i<MAX_N; i++)
    {
        a[i]=a[i-1]+a[i];
    }

    int m;
    cin >> m;
    int x, y;
    int ans[m];
    for(int i=0; i<m; i++)
    {
        cin >> x >> y;
        ans[i]=a[y]-a[x-1];
    }

    for(int i=0; i<m; i++)
    {
        cout << ans[i] << endl;
    }



    return 0;
}
