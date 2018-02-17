#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n, r = 0, s = 0;
    vector<int> dig(10002);
    cin >> n;
    dig[0] = 1;
    dig[1] = 1;
    for (int k = 2; k < n + 1; k ++)
    {
        for(int i = 1; i <= dig[0]; i ++)
        {
            dig[i] = dig[i] * k + r;
            r = 0;
            if(dig[i] > 9)
            {
                r = dig[i] / 10;
                dig[i] = dig[i] % 10;
                if(i == dig[0])
                    dig[0] ++;
            }
        }
    }

    for(int i = dig[0]; i > 0; i --)
        s += dig[i];
    cout << s;
}
