#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long any = 1, num, a = 100, exit = 0, n;
    cin >> n;
    while (any > 0)
    {
        if(n > 248)
        {
            num = n % a;
            if(num % 2 == 0)
            {
                while(num % 2 == 0)
                {
                    num = num / 2;
                    exit++;
                }
                if(num != 1)
                {
                    exit = 0;
                    a = a * 10;
                }
                else
                {
                    any = 0;
                    cout << exit << endl;
                }
            }
            else
            {
                a = a * 10;
            }
        }
        else
        {
            switch(n)
            {
            case 2:
                cout << 1 << endl;
                break;
            case 24:
                cout << 2 << endl;
                break;
            case 248:
                cout << 3 << endl;
                break;
            }
            any = 0;
        }
    }
    return 0;
}
