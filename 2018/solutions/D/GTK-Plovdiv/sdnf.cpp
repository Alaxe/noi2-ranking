#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long n,fact=1, sum=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        fact*=i;
    }
    fact=abs(fact);
    while(fact>0)
    {
        sum+=fact%10;
        fact/=10;
    }
    cout<<abs(sum)<<endl;
    return 0;
}
