#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    cin >> s;
    int cnt = 0, c = 1, st = 0, sz = s.size();
    while (cnt < sz)
    {
        if (c % 3 == 1 && c > 1)
        {
            for (int i = 1; i <= 4; i++)
            {
                if (cnt >= sz)
                {
                    cout << st << endl;
                    break;
                }
                st++;
                cnt += c;
            }
        }
        else
        {
            for (int i = 1; i <= 3; i++)
            {
                st++;
                cnt += c;
                if (cnt >= sz)
                {
                    cout << st << endl;
                    break;
                }
            }
        }
        c++;
    }
}
