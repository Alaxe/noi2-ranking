#include <iostream>
using namespace std;
int  main()
{
    long long n,m,i=0,maximum=0,kolko=0,dokolko=0;
    cin>> n;
    long long c[n];
    for(i=0; i<n; i++)
    {


        cin>>c[i];
    }
    cin>>m;
    for(i=0; i <n; i++)
    {
        if(c[i]>maximum)
        {

            maximum=c[i];
        }
    }
    kolko=maximum*n;
    for(i=0; i<n; i++)
    {
        dokolko=dokolko+c[i];
    }

    cout<<(kolko-dokolko)*m<<endl;
    return 0;
}
