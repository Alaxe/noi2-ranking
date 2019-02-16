#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[100],c=1,b,f=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(f==0)
    {
        f=1;
        b=c*c;
        for(int i=0;i<n;i++)
        {
            if(b%a[i]!=0)f=0;
        }
        c++;
    }
    cout<<c-1<<endl;
    return 0;
}
