#include<iostream>
using namespace std;
int main()
{
    long int k, n, fr, mul, add, mod, max, in, br;
    long long int sum;
    cin>>n>>k>>fr>>mul>>add>>mod;
    max=fr;
    in=0;
    sum=fr;
    for(long int i=1; i<n; i++)
    {
        fr=((fr*mul)+add)%mod;
        if(fr>=max)
        {
            max=fr;
            in=i;
        }
        if(i-k<in)
        {
            sum+=max;
        }
        else
        {
            fr=max;
            i=in;
            max=((fr*mul)+add)%mod;
            in++;
            for(long int j=0; j<k; j++, i++)
            {
                fr=((fr*mul)+add)%mod;
                if(fr>=max)
                {
                    max=fr;
                    in=i;
                }
            }
            sum+=max;
        }
    }
    cout<<sum<<endl;
}
