#include<bits/stdc++.h>
using namespace std;

long long a[100000000];

int main()
{
    long long n;
    cin >> n;

    a[0]=1;
    long long k=1,p;
    for(long long i=2; i<=n; i++)
    {
        long long m=10;
        while(i%m==0) m*=10;
        m/=10;
        if(i/m!=1)
        {
            p=0;
            for(long long j=0; j<k; j++)
            {
                a[j]=a[j]*(i/m)+p;
                p=a[j]/10;
                a[j]%=10;
            }
            while(p>0)
            {
                a[k]=p%10;
                p/=10;
                k++;
            }
        }
    }

    long long sum=0;
    for(long long i=0; i<k; i++) sum+=a[i];

    cout << sum << endl;

    return 0;
}
