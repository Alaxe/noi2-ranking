#include <iostream>
#include <cmath>
using namespace std;
int nod (int a,int b)
{
    while (true)
    {
        if (b>a)swap(a,b);
        if (b==0)return a;
        a=a%b;
    }
}
int main ()
{
int a[10000],n,k,nok=1;
cin>>n>>k;
for (int i=0;i<n;i++)
{
    cin>>a[i];
    nok=(nok*a[i])/nod(nok,a[i]);
}
if (k==0)
{
    cout<<nok<<endl;
    return 0;
}
int j;
long long c;
if (nok==1)
{cout<<1<<endl;
return 0;
}
for(int i=sqrt(nok);;i++)
{   c=1;
    for (j=0;j<k;j++)
    {
    c=c*i;
    if (c<0)break;

    if (c%nok==0)
    {
        cout<<i<<endl;
        return 0;
    }

    }
}
}
/*10 4
2 4 8 16 32 64 128 256 512 1024*/
