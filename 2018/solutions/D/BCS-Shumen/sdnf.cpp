#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int sumerinio(long long int s)
{
    long long int sum2=0;
    while(s!=0)
    {
        sum2+=s%10;
        s=s/10;
    }
    return sum2;
}
int main()
{
    long long int n;
    cin>>n;
    long long int i=1;
    long long int sum=1;
    while(i<=n)
    {
        sum=sum*i;
        i++;
    }
    cout<<sumerinio(sum)<<endl;

return 0;
}
