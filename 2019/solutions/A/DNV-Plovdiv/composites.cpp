#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;

    cin>>n;
    for(long long i=n-25;i<=n+5;i++)
    {
        if(i%30==0)
        {
            cout<<i+26<<endl;
            break;
        }
    }
    return 0;
}
