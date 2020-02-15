#include <iostream>
using namespace std;
int main ()
{
    int n,u;
    cin>>n>>u;
    int x;
    for (int i=0;i<n;i++)
        {
            cin>>x;
            if (i!=n-1)
            cout<<x*2<<" ";
            else cout<<x*2<<endl;
        }
    return 0;
}

