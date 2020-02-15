#include<iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    if( n%6 == 1 )
    {
        if( k == 2 )
        {
            cout << 2 << endl;
        }
        else if( k == 1 )
        {
            cout << 0 << endl;
        }
        else if( k == 0 )
        {
            cout << 1 << endl;
        }
    }
    else if( n%6 == 2 )
    {
        if( k == 2 )
        {
            cout << 0 << endl;
        }
        else if( k == 1 )
        {
            cout << 2 << endl;
        }
        else if( k == 0 )
        {
            cout << 1 << endl;
        }
    }
    else if( n%6 == 3 )
    {
        if( k == 2 )
        {
            cout << 0 << endl;
        }
        else if( k == 1 )
        {
            cout << 1 << endl;
        }
        else if( k == 0 )
        {
            cout << 2 << endl;
        }
    }
    else if( n%6 == 4 )
    {
        if( k == 2 )
        {
            cout << 1 << endl;
        }
        else if( k == 1 )
        {
            cout << 0 << endl;
        }
        else if( k == 0 )
        {
            cout << 2 << endl;
        }
    }
    else if( n%6 == 5 )
    {
        if( k == 2 )
        {
            cout << 1 << endl;
        }
        else if( k == 1 )
        {
            cout << 2 << endl;
        }
        else if( k == 0 )
        {
            cout << 0 << endl;
        }
    }
    else if( n%6 == 0 )
    {
        if( k == 2 )
        {
            cout << 2 << endl;
        }
        else if( k == 1 )
        {
            cout << 1 << endl;
        }
        else if( k == 0 )
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
