#include <iostream>
using namespace std;
int main()
{
    long long a[720], b[720], c[720], k=0, i=0, l=1, t;
    while(cin>>a[i]>>t)
    {
        b[i]=t+a[i];
        c[i]=a[i];
        i++;
    }
    while(l==1)
    {
        l=0;
        for(int j=1; j<=i; j++)
        {
            if(a[j-1]>a[j]){swap(a[j-1], a[j]);swap(b[j-1], b[j]);swap(c[j-1], c[j]); l=1; break;}
        }
    }
    for(int j=2; j<=i; j++)
    {
        if(a[j]<b[j-1]) k=((b[j-1]-a[j]));
        b[j]+=k;
    }
    cout<<b[i]-c[i]<<endl;

   return 0;
}
