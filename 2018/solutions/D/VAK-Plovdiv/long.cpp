#include<iostream>
using namespace std;
int main()
{
    long long n,k,t=1,a,b=2;
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        t=t*10;
    }
    b=t/k;
    while(1)
    {
        a=k*b;
        if(a/t>=1)break;
        b++;
    }
    cout<<a<<endl;

    return 0;
}

