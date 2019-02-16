#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long n,k,br=0,mx=1,i,y,otg=0;
    cin>>n>>k;
    while(br<k)
    {
        for(unsigned long i=1;i<=mx;i++)
        {
            if(i==n)br++;
            otg++;
            if(br>=k)break;
        }
        for(unsigned long y=mx-1;y>=1;y--)
        {
            if(br>=k)break;
            if(y==n)br++;
            otg++;
        }
        mx++;
    }
    cout<<otg<<endl;
    return 0;
}
