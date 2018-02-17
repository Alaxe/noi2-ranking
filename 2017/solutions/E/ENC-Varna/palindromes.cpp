#include <iostream>
using namespace std;
int main ()
{
    int n,b,c=0,d=0,i,j=1;
    cin>>n;
    b=n-1;
    for (i=1;i<n;i++)
    {
        c=b*i;
        if (c%10==c/1000)d=i;

    }
    cout<<d<<" "<<b<<endl;
    cout<<d*b<<endl;
    return 0;
}
