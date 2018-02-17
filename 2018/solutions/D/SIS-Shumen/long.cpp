#include<iostream>
using namespace std;
int step(long long  y)
{
    unsigned int long long b=1,i;
    for(i=1;i<y;i++)
        b*=10;
    return b;
}
int main()
{
    long long n,k,a;
    cin>>n>>k;
    a=step(n);
    cout<<a<<endl;
    if(a%k==0)cout<<a<<endl;
    else
    {
        a=a+(k-(a%k));
        cout<<a<<endl;
    }
return 0;
}