/**
Variables:
    N: Board size (N*N)
    r: Result
    x: <>
    y: ^v
    b: Char board
    b2: Number board
Ex. limits:
    1 <= N <= 100
Pr. limits:
    1 <= N <= 721
    Can easily be tricked into thinking another path will give more points
**/

#include <iostream>

using namespace std;

short N, r, x, y;

int main()
{
    cin >> N;
    char b[N*2][N];
    short b2[N][N];
    for (y = 0; y < N; y++)
    {
        for (x = 0; x < N * 2; x++)
        {
            cin >> b[x][y];
        }
    }
    for (y = 0; y < N; y++)
    {
        for (x = 0; x < N * 2; x += 2)
        {
            if (b[x][y] > '1' && b[x][y] <= '9')
            {
                b2[x/2][y] = b[x][y] - '0';
            }
            else if (b[x][y] == 'A')
            {
                b2[x/2][y] = 1;
            }
            else if (b[x][y] == 'T')
            {
                b2[x/2][y] = 10;
            }
            else if (b[x][y] == 'J')
            {
                b2[x/2][y] = 11;
            }
            else if (b[x][y] == 'Q')
            {
                b2[x/2][y] = 12;
            }
            else if (b[x][y] == 'K')
            {
                b2[x/2][y] = 13;
            }
        }
    }
    /**
    for (y = 0; y < N; y++)
    {
        for (x = 0; x < N; x++)
        {
            if (b2[x][y] < 10)
            {
                cout << "0";
            }
            cout << b2[x][y] << " ";
        }
        cout << endl;
    }
    **/
    for (x = 0; x != N - 1 || y != 0; )
    {
        for (y = N - 1; y != 0 || x != N - 1; )
        {
            r += b2[x][y];
            if (x < N - 1 && y == 0)
            {
                x++;
            }
            else if (x == N - 1 && y > 0)
            {
                y--;
            }
            else if (x != N - 1 && y != 0 && b2[x+1][y] > b2[x][y-1])
            {
                x++;
            }
            else if (x != N - 1 && y != 0 && b2[x+1][y] <= b2[x][y-1])
            {
                y--;
            }
        }
    }
    r += b2[x][y];
    cout << r;
    return 0;
}
