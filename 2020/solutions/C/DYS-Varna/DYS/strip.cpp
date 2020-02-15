#include<iostream>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    if(k==1 || k==n)
        cout<<1<<endl;
    else
    {
        long long f=1;
        for(int i=1;i<=n-1;i++)
            f=f*i;
        cout<<f/k<<endl;
    }
    return 0;
}
