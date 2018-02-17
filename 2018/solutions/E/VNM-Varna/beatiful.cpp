#include<iostream>
using namespace std;
int main()
{
    unsigned long long a=1, b;
    int n, k;
    cin>>n>>k;
    if(n==1) cout<<0<<endl;
    else
    {
        while(n)
        {
            a*=10;
            n--;
        }
        a/=10;
        if(a%k==0) b=a;
        else
        {
            b=a+k-a%k;
        }
        if(b>=a*10) cout<<"NO\n";
        else cout<<b<<endl;
    }
    return 0;
}
