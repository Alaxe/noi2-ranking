#include <iostream>

using namespace std;

int main()
{
    unsigned long long m, n;
    cin >> m >> n;

    unsigned long long counter = 0;
    for(unsigned long long i = m; i <= n; i++)
    {
        if(i * (i + 1) <= n)
        {
            counter += 1;
        }
        else
        {
            break;
        }
    }

    cout << counter << endl;

    return 0;
}
