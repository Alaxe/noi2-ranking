#include<iostream>
using namespace std;
long long a[100000000];
int main ()
{
    long long ia=0,brn=0,n,k;
    cin>>n>>k;
    for(long long i=1;i<1400;i++)
    {
        for(long long j=1;j<=i;j++)
        {
            a[ia]=j;
            ia++;
        }
        for(long long j=i-1;j>=1;j--)
        {
            a[ia]=j;
            ia++;
        }
    }
    for(int i=0;i<100000000;i++)
    {
        if(a[i]==n)
        {
            brn++;
        }
        if(brn==k)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}
