#include<iostream>
using namespace std;

int main()
{
    long long n,m,i,br=0,d,l;
    cin>>n>>m;
    d=n;
    while(1)
    {

        while(n>0)
        {
            d=d+n%10;
            n=n/10;
        }
        n=d;
        if(d<=m)
        {
            br++;
        }
        else
        {
            break;
        }

    }

    cout<<br+1;
    return 0;
}
