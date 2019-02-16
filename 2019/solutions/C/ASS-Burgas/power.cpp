#include<iostream>///mahni q posle
#include<algorithm>
using namespace std;
int a[10000];
int main()
{
    long long mn,n,k,i,nok,nod,sum,j;
    cin>>n>>k;
    cin>>a[0];
    nod=a[0];
    nok=1;
    mn=a[0];
    for (i=1; i<n; i++)
    {
        cin>>a[i];
        if(a[i]<mn) mn=a[i];
        nod=__gcd(nod,a[i]);
        nok=(nok*a[i])/nod;
    }
    for (i=mn; i<nok; i+=mn)
    {
        sum=1;
        for (j=0; j<k; j++) sum*=i;
            if(sum%nok==0)
            {
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}
