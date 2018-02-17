#include<iostream>
#include<string>
using namespace std;
unsigned long long n, k, ch = 1;

int kz()
{
    long brc = 0, cpy = k;
    while(cpy > 0)
    {
        brc++;
        cpy/=10;
    }
    return n-brc;
}

int main ()
{
    cin >> n >> k;
    for(long i = 0; i < n - 1; i++)
    {
        ch*=10;
    }
    while( 1 )
    {
        if(ch%k==0)
        {
            cout << ch << endl;
            return 0;
        }
        else
        {
            ch++;
        }
    }
    // ne nosi pulen broy tochki
}
