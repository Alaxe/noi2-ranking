#include <iostream>
#include <time.h>
using namespace std;

struct Block
{
    short int pr;
    char ch;
} matrix[100][100];

short int f(string str)
{
    if (str[0] - '0' >= 2 && str[0]- '0' <= 9)
    {
        return str[0] - '0';
    }
    else
    {
        if (str[0] == 'A')
        {
            return 1;
        }
        if (str[0] == 'T')
        {
            return 10;
        }
        if (str[0] == 'J')
        {
            return 11;
        }
        if (str[0] == 'Q')
        {
            return 12;
        }
        if (str[0] == 'K')
        {
            return 13;
        }
    }
}

long long sc, MaxSc, curr = 0, who, much = 0;
char mass[200], cpy[200];
bool s1, s2;
long long n, myX = n - 1, myY = 0, br1 = 0, br2 = 0;
string str;

long long score(long long sc, short int a1, short int b1, long long x, long long y, long long who, long long much, bool sr)
{
    br1 = 0;
    br2 = 0;
    if (sr)
    {
        for (int i = 0; i < (n * 2) - 2; i ++)
        {
            if (mass[i] == 'r')
            {
                br1 ++;
                if (br1 == who)
                {
                    mass[i] = 'u';
                    mass[i + 1] = 'r';
                    break;
                }
            }
            if (mass[i] == 'u')
            {
                br2 ++;
                if (br2 == who)
                {
                    mass[i] = 'r';
                    mass[i + 1] = 'u';
                    break;
                }
            }
        }
        much ++;
        if (who == ((n * 2) - 2) / 2)
        {
            for (int i = 0; i < (n * 2) - 2; i ++)
            {
                cpy[i] = mass[i];
            }
        }
        who --;
        if (who == 0)
        {
            for (int i = 0; i < (n * 2) - 2; i ++)
            {
                mass[i] = cpy[i];
            }
            who = ((n * 2) - 2) / 2;
        }

    }
    //return 0;
    myX = x;
    myY = y;
    curr = 0;
    short int a = 0, b = 0;
    for (int i = 0; i < (n * 2) - 2; i ++)
    {
        //cout << "curr : " << myY << endl;
        curr += matrix[myX][myY].pr;
        //cout << matrix[myX][myY].pr << " " << myX << " " << myY << endl;;
        if (mass[i] == 'r')
        {
            myY ++;
            a ++;
        }
        if (mass[i] == 'u')
        {
            myX --;
            b ++;
        }
    }
    //cout << curr << " " << sc << endl;
    if (curr > MaxSc)
    {
        MaxSc = curr;
    }
    if (sc > MaxSc)
    {
        MaxSc = sc;
    }
    sc = curr;
    //cout << sc << endl;
    /*if (much == ((n * 2) - 2) / 2)
    {
        who --;
        much = 0;
        if (who == 0)
        {
            cout << MaxSc + matrix[0][n - 1].pr << endl;
            return 0;
        }
    }
    */
    if (much >= n * n)
    {
        cout << MaxSc + matrix[0][n - 1].pr << endl;
        return 0;
    }
    score(sc, a1, b1, n - 1, 0, who, much, 1);
}

int main()
{
    long long ans;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            cin >> str;
            matrix[i][j].pr = f(str);
            matrix[i][j].ch = str[1];
        }
    }
    for (int i = 0; i < ((n * 2) - 2) / 2; i ++)
    {
        mass[i] = 'r';
    }
    for (int i = ((n * 2) - 2) / 2; i < (n * 2) - 2; i ++)
    {
        mass[i] = 'u';
    }
    ans = score(0, 0, 0, n - 1, 0, ((n * 2) - 2) / 2, 0, 0);
    ans += matrix[0][n - 1].pr;
    //cout << ans << endl;
    /*
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            cout << matrix[i][j].pr << matrix[i][j].ch << " ";
        }
        cout << endl;
    }
    */
    return 0;
}
