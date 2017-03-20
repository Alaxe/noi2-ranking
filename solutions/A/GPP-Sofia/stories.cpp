#include<iostream>
using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    long long first,mul,add,mod;
    cin>>first>>mul>>add>>mod;

    long long a[n];
    a[0] = first;
    for(int i=1;i<n;i++)
    {
        a[i] = ((a[i-1]*mul) + add)%mod;
    }
    long long intes=a[0];
    long long maxx = a[0];
    long long maxxden = 0;
    for(long long j=1;j<n;j++)
    {
        if(j - maxxden >= k)
        {
            maxxden = j-k+1;
            maxx = a[maxxden];
        }
        long long i;
        if(k > j)
        {
            i = 0;
        }
        else
        {
            i = j - k+1;
        }
        for( ;i<=j;i++)
        {
            if(maxx<a[i])
            {
                maxx = a[i];
                maxxden = i;
            }
        }

        intes = intes + maxx;
    }


    cout<<intes;
    return 0;
}
