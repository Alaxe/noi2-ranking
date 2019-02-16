#include<iostream>
using namespace std;

int main()
{
    long long n,d,m,broqch,kolkosa=0;
    cin>>n>>m;
    while(n<=m)
    {
        kolkosa=kolkosa+1;
        d=n;
        for(broqch=1;broqch<=7;broqch++)
        {
            if(n!=0)
            {
                d=d+n%10;
                n=n/10;
            }
            else
            {
                broqch=broqch+7;
            }
        }
        n=d;
    }
    cout<<kolkosa<<endl;
    return 0;
}
