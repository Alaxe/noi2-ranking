#include<iostream>
using namespace std;

int n,k,i;

int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        k=i*i-(i-1);
    }
    cout<<k<<endl;
    return 0;
}
