#include <iostream>
using namespace std;

int main()
{
    long long br=0;
    unsigned long long n;
    cin>>n;
    unsigned long long y=1,h=1;
    for(unsigned long long i=n;i>1;i--)
    {
        if(i>20)
        {
            h=y*i%100000000000000000000;
        }
        y=y*i;
    }
    while(y!=0)
    {
        if(n>20)
        {
            br=y%10+br+h%10;
            y=y/10;
            h=h/10;
        }
        else
        {
             br=y%10+br;
            y=y/10;
        }

    }
    cout<<br;
    return 0;
}
