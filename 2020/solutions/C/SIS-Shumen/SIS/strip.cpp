#include <iostream>
using namespace std;
const int maxn=64;
int n,k;
long long ptr[maxn][maxn];
/// ptr-pascal's triangular
void solve()
{
    ptr[1][1]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
        ptr[i][j]=ptr[i-1][j-1]+ptr[i-1][j];
    cout<<ptr[n][k]<<endl;
}
int main ()
{
    cin>>n;
    cin>>k;
    solve();
return 0;
}
