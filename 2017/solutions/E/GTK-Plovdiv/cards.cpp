#include<iostream>
using namespace std;
int main()
{
    long long n,a,b,br=1,p1=0,p2=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a>>b;
        if((a<=p1&&b<=p2)||(a<=p2&&b<=p1)) {br++;}
        p1=a; p2=b;
    }
    cout<<br<<endl;
    return 0;
}
