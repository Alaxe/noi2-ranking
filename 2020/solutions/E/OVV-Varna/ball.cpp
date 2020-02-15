#include<iostream>
using namespace std;
int main( )
{
    long long n, x, i, a, b, c;
    cin >> n >> x;
    a = 0;
    b = 1;
    c = 2;
    for(i=n;i>=1;i--)
    {
        if(i % 2 == 0)
        {
            swap(c, b);
        }
        else if(i % 2 == 1)
        {
            swap(a, b);
        }
    }
    if(a == x) cout << 0;
    else if(b == x) cout << 1;
    else cout << 2;
    cout << endl;
}
