#include<iostream>
using namespace std;
int main()
{
    int n;
    long long a=1;
    long long  a1=1;
    int c=0;
    long long i=1;

    cin>>n;
    if( n<4)
    {
        if( n<3)
        {
            if( n<2)
            {

                cout<<1;
            }
            else
            {
                cout<<2;
            }

        }
        else
        {
            cout<<6;
        }
    }
    else
    {
        for(  int b=1; b<n ; b++ )
        {
            a=a*b;

        }
        a=a*n;
        a1=a;
        while(    a>9)
        {

            a=a/10;
            i++;


        }
        for ( int p=0; p!=i ; p++)
        {
            c=a1%10+ c;
            a1=a1/10;

        }
        cout<<c;
    }
}
