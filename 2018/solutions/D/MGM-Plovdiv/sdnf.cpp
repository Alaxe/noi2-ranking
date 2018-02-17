#include <bits/stdc++.h>
using namespace std;
long long n, a[100000000]={0}, sb=0, d=0, pr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a[0]=1;
    for(int i=2; i<=n; i++)
    {
        pr=0;
        for(int j=0; j<=d; j++)
        {
            a[j]*=i;
            a[j]+=pr;
            pr=a[j]/10;
            a[j]%=10;
        }
        if(pr!=0)
        {
           while(pr>0)
           {
               d++;
               a[d]=pr%10;
               pr/=10;
           }
        }
    }
    for(int i=d; i>=0; i--)  sb+=a[i];
    cout<<sb<<endl;
    return 0;
}
