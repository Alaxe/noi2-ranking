#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k=1;
    long long sum=0;
    cin>>n;
    while(n>1)
    {
        k*=n;
        n--;
    }
    while(k>1)
    {
        sum+=k%10;
        k/=10;
    }
    cout<<sum<<endl;
}
