#include <bits/stdc++.h>

using namespace std;

int main()
{
    int input[3];

    for(int i = 0; i < 3; i++)
    {
        cin >> input[i];
    }

    int numbersCount = input[0];
    int firstContainerVolume = input[1];
    int secondContainerVolume = input[2];

    int numbers[numbersCount];

    for(int i = 0; i < numbersCount; i++)
    {
        cin >> numbers[i];
    }
    return 0;
}
