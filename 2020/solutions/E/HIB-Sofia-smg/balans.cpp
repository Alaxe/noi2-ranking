#include<iostream>
using namespace std;
int main()
{
    long long n;
    char a,b,c,d;
    cin>>n;
    cin>>a>>b>>c>>d;
    if(n==1)
    {
        cout<<0;
    }
    if(n=2)
    {
        int x=n/10;
        int y=n%10;
        if(((x==a || x==b) && (y==c || y==d)) || (x==c || x==d) && (y==a || y==b))
        {
            cout<<2;
        }
        else
        {
            cout<<0;
        }
    }
    return 0;
}
