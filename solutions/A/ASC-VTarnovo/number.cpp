#include <iostream>
using namespace std;
long long n,m;
long long ans(long long x)
{
    long long l=0,r=1000000000;
    long long mid;
     ///cout<<x<<endl;
    while(l<r)
    {
        mid=(l+r)/2;

        if(mid*(mid+1)<x)
            l=mid+1;
        else if(mid*(mid+1)>x)
            r=mid-1;
        else
        {
            l=mid;
            r=mid;
            break;
        }
    }
    mid=(l+r)/2;
    long long m1=(mid-1)*mid,m2=mid*(mid+1),m3=(mid+1)*(mid+2);
    ///cout<<x<<" "<<m1<<" "<<m2<<" "<<m3<<endl;
    if(x>=m1&&x<m2)
        return mid-1;
    else
        return mid;

}
int main()
{
    cin>>m>>n;
    cout<<ans(m)-ans(n-1)<<endl;
}
