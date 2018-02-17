#include<iostream>
using namespace std;

long long n, num;
int l;

int main()
{
    cin >> n;
    cin >> l;
    int lost[l];
    for (int i = 0 ; i < l; i ++)
    {
        cin >> lost[i];
    }
    for (int i = 0; i < n; i ++)
    {
        num ++;
        long long cnum = num;
        while (cnum > 0)
        {
            int a = cnum % 10;
            cnum /= 10;
            bool toBreak = false;
            for (int i = 0; i < l; i ++)
            {
                if (a == lost[i])
                {
                    toBreak = true;
                    break;
                }
            }
            if (toBreak)
            {
                i --;
                break;
            }
        }
    }
    cout << num << '\n';
    return 0;
}

