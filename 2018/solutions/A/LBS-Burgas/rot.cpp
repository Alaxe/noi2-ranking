#include <iostream>
#include <string>
using namespace std;

int b;

int toDec(char m)
{
    if ((int)m < 58) {return ((int)m - 48);}
    else {return ((int)m - 55);}
}

char toChar(int m)
{
    if(m < 10) {return (char)(m+48);}
    else {return (char)(m+55);}
}

int main()
{
    cin >> b;

    string num; string fake_num; int length;
    for (int i = 0; i < 4; i++)
    {
        cin >> fake_num;
        num = '0' + fake_num; length = num.length();

        char A = '0', B = num[1];
        for(int j = 1; j < length; j++)
        {
            int x = toDec(A)*b + toDec(B);
            num[j] = toChar(x / (b-1));
            A = toChar(x % (b-1));
            B = (j == length - 1 ? '0' : num[j+1]);
        }

        if(toDec(A) != 0)
        {
            cout << '0';
        }
        else
        {
            int rem = 0, n; string X; X.resize(length);
            for(int j = 0; j < length - 1; j++)
            {
                n = 1 + rem + toDec(num[length-j-1]);
                X[j] = toChar(n % b);
                rem = n / b;
            }

            for(int j = length - 2; j >= 0; j--)
            {
                cout << X[j];
            }
        }
        cout << endl;

    }
    return 0;
}
