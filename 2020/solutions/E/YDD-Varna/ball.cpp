#include <iostream>
using namespace std;
int main ()
{
    int n, x;
    cin >> n >> x;
    while (n > 0)
    {
        if (x == 0 && n%2 == 0);
        else if (x == 0 && n%2 == 1) x = 1;
        else if (x == 1 && n%2 == 0) x = 2;
        else if (x == 1 && n%2 == 1) x = 0;
        else if (x == 2 && n%2 == 0) x = 1;
        else;
        n--;
    }
    cout << x << endl;
    return 0;
}
