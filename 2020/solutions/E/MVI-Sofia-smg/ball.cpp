#include <iostream>
#include <windows.h>

using namespace std;

INT main()
{
    BOOL Ball[3];
    INT Index;
    LONG64 Operations;

    for (INT i = 0; i < 3; i++)
    {
        Ball[i] == FALSE;
    }

    cin >> Operations;
    cin >> Index;

    Ball[Index] = TRUE;

    Operations %= 6;
    Operations++;

    for (INT i = 1; i <= Operations; i++)
    {
        if (i % 2 == 1)
        {
            swap (Ball[1], Ball[2]);
        }
        else
        {
            swap (Ball[0], Ball[1]);
        }
    }

    if (Ball[0] == TRUE) { cout << "0"; }
    if (Ball[1] == TRUE) { cout << "1"; }
    if (Ball[2] == TRUE) { cout << "2"; }
}
