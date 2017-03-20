#include <iostream.h>
#include <math.h>

int main()
{
    long long n, k;
    long long mul, add, mod;
    long long i, j;
    long long h, s=0;
    
    cin >> n >> k;
    long long p[n];
    cin >> p[0] >> mul >> add >> mod;
    
    for(i=1; i<n; i++)
        p[i] = (p[i-1]*mul+add)%mod;
    
    for(i=n-1; i>=0; i--)
    {
        h=0; 
        for(j=i; j>i-k; j--)
        {
            if(j>=0)
            {
                if(p[j] > h)
                {
                         h=p[j];
                         
                }
            }
        }  
        s+=h; 
    }
    cout << s << endl;
}
