#include<iostream>

using namespace std;

long long a[55][55];

long long rez(long long n, long long k)
{
    if(n <= k || k == 1)
    {
        return 1;
    }
    
    if(a[n - 1][k] == 0)
    {
        a[n - 1][k] = rez(n - 1, k);
    }
    
    if(a[n - 1][k - 1] == 0)
    {
        a[n - 1][k - 1] = rez(n - 1, k - 1);
    }
    
    return a[n - 1][k] + a[n - 1][k - 1];
}

int main()
{
    long long n,k;
    cin>>n>>k;
    
    cout<<rez(n,k)<<endl;
    
    return 0;
}