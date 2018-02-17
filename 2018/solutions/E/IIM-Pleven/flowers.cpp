#include <iostream>
using namespace std;

long long n,Max,gh,i,g,k,a;

int main ()
{
    cin>>n;
    Max=a+1;
    gh=0;
    g=0;
    for (i=1;i<=n;i++)
    {
        cin>>a;
        if (Max<a)
        {
            Max=a;
        }
        else
        if (Max>a)
        {
            g=Max-a;
        }
    gh=gh+g;
    }
    cin>>k;
    cout<<gh*k<<endl;


    return 0;
}
