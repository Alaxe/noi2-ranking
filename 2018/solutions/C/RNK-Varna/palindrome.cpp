#include<iostream>
#include<cmath>
using namespace std;
int main ()
{
    unsigned long long n, n1, i, m = 1;
    int br, b, s;
    cin >> n;
    n1 = n;

    for( br = 0; n1 > 0; ++br )
    {
        n1 /= 10;
    }
    n1 = n;
    for( i = 0; i < ceil(br / 2.0); ++i )
    {
        for( int j = 1; j < (br - i); ++j )
        {
            n1 /= 10;
        }
        b = n1 % 10;
        n1 = n;

        for( int j = 0; j < i; ++j )
        {
            n1 /= 10;
        }
        s = n1 % 10;

        if(s < b)n += (b - s) * m;
        else if(s > b)n += (b + 10 - s) * m;

        n1 = n;
        m *= 10;
    }

    m = 1;

    if(b < s && br % 2 == 0)
    {
        for( int j = 0; j < br / 2 - 1; ++j )m *= 10;
        n += m;
    }

    for( int j = 1; j < br; ++j )
    {
        n1 /= 10;
    }
    b = n1 % 10;
    s = n % 10;
    if(b > s)++n;

    cout << n << endl;

    return 0;
}

///
///
///          *
///         /|\
///        //|\\
///       ///|\\\
///      ////|\\\\
///     /////|\\\\\
///          |
///          |
