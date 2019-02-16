#include <iostream>
#include <algorithm>

using namespace std;
long long a[10001];
int main()
{
    long long n,k;
    long long i=0,ch,ch1,br=0;

    cin>>n>>k;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
 sort(a,a+n);

    ch=a[n-1]*a[n-2];
    ch1=ch;
    for(i=0;i<k-1;i++)
    {
        ch=ch*ch1;
    }

    for(i=0;i<n;i++)
    {
       if(ch%a[i]==0) br++;
    }

    if(br==n) cout<<ch1;

    return 0;
}
