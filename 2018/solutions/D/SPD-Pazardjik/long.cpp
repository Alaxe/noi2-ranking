#include <iostream>
using namespace std;
int main()
{
    unsigned long long n,k,m=1;
    cin>>n>>k;
    for(int i=1;i<n;i++)
        m*=10;
    while(m%k!=0)
        m++;
    cout<<m<<endl;
    return 0;
}
