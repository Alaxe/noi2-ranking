#include<iostream>
using namespace std;
int main()
{
    long long n,m,br=1,d,e;
    cin>>n>>m;
    if((n>=1&&n<=9)&&(m>=1&&m<=9))
    {  
        if(n=m) br=1;
        else
        {
        do
        {
            n=n*2;
            br++;
        }while(n<=m);
        }
    }
    if((n>=10&&n<=99)&&(m>=10&&m<=99))
    {
        if(n=m)br=1;
        else
        {
        do
        {
            d=n/10;e=n%10;
            n=n+d+e;br++;
        }while(n<=m);
        }
    }
    cout<<br<<endl;
    return 0;
}