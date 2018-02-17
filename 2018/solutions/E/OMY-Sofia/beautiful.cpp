#include <iostream>
using namespace std;
int main ()
{
    long long n,st=1,k,z=1,o,m,kopieNaSt;
    do
    {
        cin>>n>>k;
    }
    while(n>18 or n<1 or k<1 or k>10000000);
    for(z=1; z<n; z++)
    {
        st=st*10;
    }
    kopieNaSt=st;
    if(kopieNaSt%k!=0)
    {
        m=kopieNaSt%k;
        kopieNaSt=kopieNaSt+(k-m);
        if(kopieNaSt/st>=st or k>(st*10)-1)
        {
            cout<<"NO";
        }
        else
        {
            cout<<kopieNaSt;
        }
    }
    else
    {
        cout<<kopieNaSt;
    }
    cout<<endl;
    return 0;
}
