#include <iostream>
using namespace std;

long long n,k,z=1;

int main()
{
    cin>>n>>k;

    for(int i=1; i<n; i++)z*=10;

    if(z%k==0)
    {
        cout<<z+k-(k-(z%k))<<endl;
    }
    
    else
    {
        cout<<z+k-(z%k)<<endl;
    }

    return 0;
}
