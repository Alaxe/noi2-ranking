#include <iostream>
using namespace std;
long long fact(long long n)
{
    if (n==0) return 1;
    return fact(n-1)*n;
}
long long sumdig(long long n)
{
    int sum=0;
    while (n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<sumdig(fact(n))<<endl;

    return 0;
}
