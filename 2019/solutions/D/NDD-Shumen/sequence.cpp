#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    long long int n,k;
    cin>>n>>k;
    if(n==1&&k==1)
    {
        cout<<1<<endl;
        return 0;
    }
    if(k==1)
    {
        long long int m=n-2;
        long long int i=0;
        long long int p=3;
        long long int u=2;
        while(i<m)
        {
            i++;
            u+=2;
            p+=u;
        }
        cout<<p<<endl;
        return 0;
    }
    if(n==k)
    {
        cout<<k*3<<endl;
        return 0;
    }

return 0;
}
