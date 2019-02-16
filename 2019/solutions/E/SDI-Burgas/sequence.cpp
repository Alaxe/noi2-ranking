#include <iostream>

using namespace std;

int main()
{
    int fullnum, n, i, nfi;
    fullnum = 0;
    i = 1;
    nfi = 1;
    cin >> n;
    while (nfi < n + 1)
    {
        while (nfi > i)
        {
            //cout << i;
            fullnum += 1;
            i++;
        }
         while (i > 0)
        {
            //cout << i;
            fullnum += 1;
            i--;
        }
        nfi++;
    }

    if (n != 1)
    {

        fullnum -= n--;
    }

    cout << endl;
    cout << fullnum << endl;

    return 0;
}
