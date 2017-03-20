#include <iostream>
#include <vector>
using namespace std;
const long long MOD=1234567890412345;
int n,a[1000];
long long brp[1000][1000];
long long ans;
vector<int> ind[1001];
int main( )
{
    int n,i,j,k;
    cin>>n;
    cin>>a[0];
    ind[a[0]].push_back(0);
    for(i=1;i<n;i++)
    {
        cin>>a[i];
        ind[a[i]].push_back(i);
        for(j=1;j<1000;j++)
        {
           if(a[i]<=j)break;
           for(k=0;k<ind[a[i]-j].size( );k++)
           {
               brp[j][i]=brp[j][i]+brp[j][ind[a[i]-j][k]]+1;
           }
           ans=(ans+brp[j][i])%MOD;
           brp[j][i]=brp[j][i]%MOD;
        }
    }
    cout<<ans<<endl;
}
