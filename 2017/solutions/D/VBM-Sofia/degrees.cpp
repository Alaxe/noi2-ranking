#include <iostream>

using namespace std;

int main()
{
    string strEnter;
    int Nmb[3] = {3, 3, 4};
    long long Size, i, answer = 0, j, k;

    cin >> strEnter;
    Size = strEnter.size();
    if (Size - 34 <= 0)
    {
        if (Size <= 3)
        {
            for (i = 0; i < 3; i ++)
            {
                if (Size >= i + 1)
                {
                    answer = i + 1;
                }
            }
            cout << answer << endl;
            return 0;
        }
        if (Size <= 9)
        {
            for (i = 3,j = 4; i < 9; i += 2, j ++)
            {
                if (Size >= i + 2)
                {
                    answer = j;
                }
            }
            cout << answer << endl;
            return 0;
        }
        if (Size <= 18)
        {
            for (i = 9,j = 7; i < 18; i += 3, j ++)
            {
                if (Size >= i + 3)
                {
                    answer = j;
                }
            }
            cout << answer << endl;
            return 0;
        }
        if (Size <= 34)
        {
            for (i = 18,j = 10; i < 34; i += 4, j ++)
            {
                if (Size >= i + 4)
                {
                    answer = j;
                }
            }
            cout << answer << endl;
            return 0;
        }
    }
    Size = Size - 34;
    while (Size > 0)
    {
        i = 5;
        j = 23;
        Size = Size - (3 * (i + i + 1) + 4 * (i + 2));
        i += 3;
        if (Size == 0)
        {
            cout << j << endl;
            return 0;
        }
        if (Size < 0)
        {
            for (k = 0; k < 4; k ++)
            {
                Size += i - 1;
                if (Size == 0)
                {
                    cout << j - (k + 1) << endl;
                    return 0;
                }
            }
            j -= 4;
            for (k = 0; k < 3; k ++)
            {
                Size += i - 2;
                if (Size == 0)
                {
                    cout << j - (k + 1) << endl;
                    return 0;
                }
            }
            j -= 3;
            for (k = 0; k < 3; k ++)
            {
                Size += i - 3;
                if (Size == 0)
                {
                    cout << j - (k + 1) << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
