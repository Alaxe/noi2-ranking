#include <iostream>
#include <stdint.h>
using namespace std;

int16_t n, a[1024];
int16_t dp[1024][1024];

const long long MOD=((long long)(123456789012345));

int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        for(int j=0; j<i; j++)
        {
            if(a[i]>a[j])
            {
                int r=a[i]-a[j];
                dp[i][r]=(dp[j][r]+1)%MOD;
            }
        }
    }
    cout<<res<<endl;

    return 0;
}
