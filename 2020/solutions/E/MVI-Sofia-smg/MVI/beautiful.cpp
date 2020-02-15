#include <iostream>
#include <windows.h>

using namespace std;



INT NumberOfNumbers(LONG64 Number)
{
    INT Numbers = 0;
    LONG64 Current = Number;
    while (Current != 0)
    {
        Current /= 10;
        Numbers++;
    }
    return Numbers;
}

BOOL SameNums(LONG64 Num)
{
    BOOL SameNums = FALSE;
    LONG64 Devidable = 0;
    for (INT i = 0; i < NumberOfNumbers(Num); i++)
    {
        Devidable *= 10;
        Devidable++;
    }
    if (Num % Devidable == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main()
{
    LONG64 Pages;
    cin >> Pages;
    INT Output = 0;
    /*for (LONG64 i = 1; i <= Pages; i++)
    {
        if (SameNums(i))
        {
            Output++;
        }
    }*/
    LONG64 Current = 0;
    for (INT i = 1; i <= 18; i++)
    {
        Current *= 10;
        Current++;
        for (INT j = 1; j <= 9; j++)
        {
            if (Current * j <= Pages)
            {
                Output++;
            }
        }
    }
    cout << Output;
}
