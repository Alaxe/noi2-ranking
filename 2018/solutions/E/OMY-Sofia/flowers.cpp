#include <iostream>
using namespace std;
int main ()
{
    long long n,q,naiVisoko=-1,broqch,brk=0;

    cin>>n;
    long long visochini[n];
    for(broqch=0; broqch<n; broqch++)
    {
        cin>>visochini[broqch];
        if(visochini[broqch]>naiVisoko)
        {
            naiVisoko=visochini[broqch];
        }
    }

    cin>>q;
    for(broqch=0; broqch<n; broqch++)
    {
        while(visochini[broqch]!=naiVisoko)
        {
            visochini[broqch]++;
            brk++;
        }
    }

    cout<<brk*q;
    cout<<endl;
    return 0;
}
