#include <iostream>
using namespace std;
unsigned long long n, m, f[300];
int main ()
{
    cin >>n>>m;
    for (int j=1; j<=n; j++) f[j]=1;
    for (int i=2; i<=m; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (i==j) f[j]++;
            else if (j>i) f[j]+=f[j-i];
        }
    }
    cout <<f[n]<<endl;
    return 0;
}
