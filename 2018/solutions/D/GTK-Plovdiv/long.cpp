#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long n,k;
    cin>>n>>k;
    long long num = pow(10, n-1);
    long long r = num%k;
    if(r!=0)
        cout<<num+(k-r)<<endl;
    else
        cout<<num<<endl;
    return 0;
}
