#include <iostream>
using namespace std;
int main()
{
    long long n;
    int x, a, b;
    cin >> n >> x;
    if ( x == 0 )
    {
        a = 1;
        b = 2;
         for ( int br = n; n >= 1; n-- )
    {
        if ( br % 2 == 0)
        {
          if ( (x == 1 || x == 2) && (b == 1 || b == 2) ) swap(x,b);
          if ( (x == 1 || x == 2) && (a == 1 || a == 2) ) swap(x,a);
          if ( (a == 1 || a == 2) && (b == 1 || b == 2) ) swap(a,b);
        }
        else
        {
          if ( (x == 1 || x == 0) && (b == 1 || b == 0) ) swap(x,b);
          if ( (x == 1 || x == 0) && (a == 1 || a == 0) ) swap(x,a);
          if ( (a == 1 || a == 0) && (b == 1 || b == 0) ) swap(a,b);
        }
    }
    cout << x << endl;
    }
    if ( x == 1 )
    {
        a = 2;
        b = 0;
         for ( int br = n; n >= 1; n-- )
    {
        if ( br % 2 == 0)
        {
          if ( (x == 1 || x == 2) && (b == 1 || b == 2) ) swap(x,b);
          if ( (x == 1 || x == 2) && (a == 1 || a == 2) ) swap(x,a);
          if ( (a == 1 || a == 2) && (b == 1 || b == 2) ) swap(a,b);
        }
        else
        {
          if ( x == 1 || x == 0 && b == 1 || b == 0 ) swap(x,b);
          if ( x == 1 || x == 0 && a == 1 || a == 0 ) swap(x,a);
          if ( a == 1 || a == 0 && b == 1 || b == 0 ) swap(a,b);
        }
        cout << x << endl;
    }
    }
    if ( x == 2 )
    {
        a = 1;
        b = 0;
         for ( int br = n; br >= 1; br-- )
    {
        if ( br % 2 == 0)
        {
          if ( (x == 1 || x == 2) && (b == 1 || b == 2) ) swap(x,b);
          if ( (x == 1 || x == 2) && (a == 1 || a == 2) ) swap(x,a);
          if ( (a == 1 || a == 2) && (b == 1 || b == 2) ) swap(a,b);
        }
        else
        {
          if ( (x == 1 || x == 0) && (b == 1 || b == 0) ) swap(x,b);
          if ( (x == 1 || x == 0) && (a == 1 || a == 0) ) swap(x,a);
          if ( (a == 1 || a == 0) && (b == 1 || b == 0) ) swap(a,b);
        }
    }
    cout << x << endl;
    }
    return 0;
}
