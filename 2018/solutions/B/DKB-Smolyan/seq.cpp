#include <iostream>
using namespace std;
int main()
{
    int n,m,k=0;
    cin>>n;
    cin>>m;
    for (int i=m; i>1; i--)
    {
        for (int j=0; j<=n; j++)
        {
            if(i+j==n)
            {
                if(j==0) {k++;};
                k=k+j;
            };
            cout<<i<<" "<<j<<endl;
        }
    }
    cout<<k;
}
