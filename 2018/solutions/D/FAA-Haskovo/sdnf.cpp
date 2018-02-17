#include<iostream>

using namespace std;

int main()
{
    unsigned long long n,fac=1,sum=0;
    cin>>n;
    for(int i=2;i<=n;i++)
        fac=fac*i;
    while(fac!=0)
    {
        sum=sum+fac%10;
        fac=fac/10;
    }
    cout<<sum<<endl;
    return 0;
}
