#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

INT main()
{
    INT Balls;
    cin >> Balls;
    INT Statistics[4] = { 0, 0, 0, 0 };
    char Nums[Balls + 1];
    cin >> Nums;
    for (int i = 0; i < Balls; i++)
    {
        Statistics[Nums[i] - 'a']++;
    }
    cout << min(min(Statistics[0], Statistics[1]), min(Statistics[2], Statistics[3])) * 4;
}
