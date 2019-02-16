#include<iostream>
using namespace std;
int main()
{
    long long n,m,n1=0,n2=0,n3=0,n4=0,br=0,i;
    cin>>n>>m;

    while(n<=m)
    {
        if(n>0&&n<10)
        {
            n1=n;
            n=n+n1;

        }
        if(n>=10&&n<100)
        {
            n1=n/10;
            n2=n%10;
            n=n+n1+n2;

        }
        if(n>=100&&n<1000)
        {
            n1=n/100;
            n2=n%100/10;
            n3=n%10;
            n=n+n1+n2+n3;
        }
        if(n==1000)
        {
            n1=1;
            n=n1+n2+n3+n4;

        }
        br++;
    }
    cout<<br<<endl;
    return 0;
}
