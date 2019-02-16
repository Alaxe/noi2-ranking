#include <iostream>
using namespace std;
int main()
{
    long long br=0,d,n,m,a,b,c;
    cin>>n;
    cin>>m;
    if(n&&m>0&&n&&m<=100)
    {
        n<m;
        a=n/10;
        b=n%10;
        while(n<=m)
        {
            br++;
            d=n+a+b;
            n=d;
        }
    }
         if(n&&m>100&&n&&m<=1000)
    {
        n<m;
        a=n/100;
        b=n/10/10;
        c=n%10;
        while(n<=m)
        {
            br++;
            d=n+a+b+c;
            n=d;
        }
    cout<<br<<endl;
    }
}

