#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string num;
int main()
{
    cin >> num;
    bool is = 1;
    int sz = num.size();
    for (int i = 0; i < sz; i++)
        if (num[i] != '9')
        {
            is = 0;
            break;
        }
        string s = num;
    if (is)
    {
        string ans = "";
        ans += '1';
        for (int i = 1; i <= sz-1; i++)
            ans += '0';
        ans += '1';
        num = ans;
        cout << num << endl;
    }
    else
    {
        int pos1, pos2;
        if (sz % 2 == 0)
        {
            pos1 = sz/2-1;
            pos2 = sz/2;
            string t = num;
            bool can = 1;
            while (pos1 >= 0 && pos2 < sz)
            {
                if (t[pos1] > t[pos2])
                {
                    t[pos2] = t[pos1];
                    break;
                }
                if (t[pos1] < t[pos2])
                {
                    can = 0;
                    break;
                }
                pos1--;
                pos2++;
            }
            if (can && pos1 >= 0)
            {
                for (int i = 0; i < pos1; i++)
                    t[sz-i-1] = t[i];
                can = 1;
            }
            pos1 = sz/2-1;
            pos2 = sz/2;
            while (pos1 >= 0 && pos2 < sz)
            {
                if (num[pos1] != '9' || num[pos2] != '9')
                {
                    if (num[pos1] > num[pos2])
                        num[pos2] = num[pos1];
                    else
                    {
                        num[pos1] = num[pos2] = num[pos1]+1;
                        for (int i = pos1+1; i <= pos2-1; i++)
                            num[i] = '0';
                    }
                    break;
                }
                pos1--;
                pos2++;
            }
            if (pos1 > 0)
            {
                for (int i = 0; i < pos1; i++)
                    num[sz-i-1] = num[i];
            }
            if (can && num > t && t > s) cout << t << endl;
            else cout << num << endl;
        }
        else
        {
            pos1 = sz/2-1;
            pos2 = sz/2+1;
            string t = num;
            bool can = 1;
            while (pos1 >= 0 && pos2 < sz)
            {
                if (t[pos1] > t[pos2])
                {
                    t[pos2] = t[pos1];
                    break;
                }
                if (t[pos1] < t[pos2])
                {
                    can = 0;
                    break;
                }
                pos1--;
                pos2++;
            }
            if (can && pos1 >= 0 && t > num)
            {
                for (int i = 0; i < pos1; i++)
                    t[sz-i-1] = t[i];
                can = 1;
            }
            pos1 = sz/2-1;
            pos2 = sz/2+1;
            if (num[sz/2] != '9')
            {
                num[sz/2]++;
                for (int i = 0; i < sz/2; i++)
                    num[sz-i-1] = num[i];
            }
            else
            {
                while (pos1 >= 0 && pos2 < sz)
                {
                    if (num[pos1] != '9' || num[pos2] != '9')
                    {
                        if (num[pos1] > num[pos2])
                            num[pos2] = num[pos1];
                        else
                        {
                            num[pos1] = num[pos2] = num[pos1]+1;
                            for (int i = pos1+1; i <= pos2-1; i++)
                                num[i] = '0';
                        }
                        break;
                    }
                    pos1--;
                    pos2++;
                }
                if (pos1 > 0)
                {
                    for (int i = 0; i < pos1; i++)
                        num[sz-i-1] = num[i];
                }
            }
            if (can && t < num && t > s) cout << t << endl;
            else cout << num << endl;
        }
    }
}

