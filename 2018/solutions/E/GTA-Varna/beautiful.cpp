#include<iostream>
using namespace std;
int main ()
{
    long long n,k,br1=1,br2=1,m,i;
    cin>>n>>k;
    for(i=1; i<=n; i++)
    {
        br1*=10;
        br2*=10;
    }
    br2/=10;
    for(i=br2; i<br1; i++)
    {
        if(i%k==0)
        {
            m=i;
            break;
        }

    }
    cout<<m<<endl;
    return 0;
}
