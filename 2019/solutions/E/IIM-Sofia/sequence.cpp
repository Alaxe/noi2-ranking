#include<iostream>
using namespace std;
int main ()
{
    long long n, a=1,i;
    cin>>n;
    long long reditsa[10000],simvoli[n];
    for(i=1; i<=n; i++)
    {
        reditsa[i]=reditsa[i]+a+i;
        simvoli[i]++;
    }

        for(i=1; i>=n; i--)
        {
            reditsa[i]=reditsa[i]-i;
            simvoli[i]++;
        }
        cout<<simvoli[i]<<endl;



    return 0;
}
