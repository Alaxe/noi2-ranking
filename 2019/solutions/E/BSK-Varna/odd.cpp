#include<iostream>
using namespace std;
int main()
{
    long long a, b, i, j, brd=0, brnd=0;
    cin >> a >> b;
    for( i=a; i<=b; i++ )
    {
        for( j=1; j<=i; j++ )
        {
            if( i%j == 0)brd++;
        }
        if( brd%2 != 0)brnd++;
        brd=0;
    }
    cout << brnd << endl;
    return 0;
}

