#include<iostream>
using namespace std;
int main()
{
    int n,f=0;
    long long min=1,max=9,k;
    cin>>n>>k;
    for(int i=1; i<n; i++)
    {
        min*=10;
    }
    for(int i=1; i<n; i++)
    {
        max*=10;
        max+=9;
    }
    for(long long i=min; i<=max; i++)
    {
        if(i%k==0)
        {
            f=0;
            cout<<i<<endl;
            break;
        }
        else f=1;
    }
    if(f==1)cout<<"NO\n";
    return 0;
}
