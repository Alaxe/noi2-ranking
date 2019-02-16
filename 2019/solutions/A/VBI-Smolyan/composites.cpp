#include <iostream>
#include <cmath>
using namespace std;

bool Prime(int p)
{
    for(int i = 2; i < p; i++)
        if(p % i == 0)
            return false;
    return true;
}
int Digits(int d)
{
    int b, digitCounter = 0;
    do
    {
        b = d % 10;
        d = d / 10;
        digitCounter++;
    }
    while(d != 0);
    return digitCounter;
}
int main()
{
    bool flag = false, defaultFlag = false;
    int n, M;
    cin >> n;
    n++;
    for(int x = n; Digits(x) < Digits(n) + 2; x++)
    {
        if(x % 2 == 0)
        {
            for(int p = 3; p < 20 ; p++)
            {
                if(Prime(p))
                    if(!Prime(pow(p, 2) + x))
                        flag = true;
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true)
        {
            cout << x;
            defaultFlag = true;
        }
    }
    if(defaultFlag == false)
        cout << 0;
}
