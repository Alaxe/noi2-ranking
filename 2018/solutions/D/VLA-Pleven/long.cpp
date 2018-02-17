#include<iostream>
using namespace std;
int main()
{
    long long n,k,i=2,j,q=1,p=9;
    cin>>n>>k;
    while(1)
    {
        q*=10;
        p+=(q*9);
        i++;
        if(i>n)break;
    }
    for(i=q;i<=p;i++)
    {
        if(i%k==0){cout<<i<<endl;return 0;}
    }


return 0;
}
