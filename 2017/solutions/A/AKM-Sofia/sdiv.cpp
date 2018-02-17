#include <iostream>
#include <cmath>

using namespace std;

long long stepen(int x, int y)
{
    if (y > 0)
    {
        return x * stepen(x, y-1);
    }
    else return 1;
}

int main ()
{
    char niz[10000];
    unsigned long long n,m;

    cin >> niz;
    cin >> n >> m;

    cout << (n*n + int(sqrt(n))*n + 1)%m;

    return 0;
}
