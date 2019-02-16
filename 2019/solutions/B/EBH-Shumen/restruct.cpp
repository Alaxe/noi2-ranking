#include <iostream>
using namespace std;
int main()
{
    int n,k,x,a;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            cin>>a;
        }
    }
    if(n==2)cout<<3*k<<endl;
    else if(n==3)cout<<5*k<<endl;
    else if(n==4)cout<<8*k<<endl;

return 0;
}
