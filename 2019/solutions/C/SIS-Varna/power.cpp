#include<iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
using namespace std;
int n,a[10002];
bool test(long long b)
{
    for(int g=1; g<=n; g++)
    {
        if((b%a[g])!=0) return false;
    }
    return true;
}
int main()
{
    long long b=1;
    int tk,k,f=0,s=0;
    cin>>n>>k;
    tk=k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=10000; i++)
    {
        while(tk)
        {
            b*=i;
            tk--;
        }
        if(test(b))
        {
            cout<<i<<endl;
            return 0;
        }
        tk=k;
        b=1;
    }
    return 0;
}
