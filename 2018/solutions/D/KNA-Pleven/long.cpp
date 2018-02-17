#include <iostream>

using namespace std;

int main()
{
    int n,k,x,j;
    cin>>n>>k;
    unsigned long long l=1;
    for(int i=1;i<n;i++)
    {
        l=l*10;
    }
    x=l%k;
    if(x%k==0)
    {
        cout<<l;
        return 0;
    }
    j=k-x;
    cout<<l+j;
    return 0;
}
