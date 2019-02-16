#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, s, k, tempk;
int br = 3, cs;

double evt, hg[4] = {0};

int main()
{
    cin >> s >> k >> a >> b >> c >> d;

    if(k > s * 4 * d)
    {
        evt = k / s / 4;

        cout << fixed << setprecision(3) << evt << " " << evt << " " << evt << " " << evt << endl;

        return 0;
    }

    cs = k / d / 4;
    k %= d * 4;

    if(cs == 0)
    {
        if(k > 4.0 * c)
        {
            evt = k / 4.0;

            cout << fixed << setprecision(3) << evt << " " << evt << " " << evt << " " << evt << endl;

            return 0;
        }

        if(2.0 * c >= k)
        {
            if(k / 2.0 >= a)
            {
                evt = k / 2.0;

                cout << fixed << setprecision(3) << evt << " " << evt << " 0.000 0.000\n";

                return 0;
            }

            else
            {
                tempk = k;

                if(tempk >= a)
                {
                    hg[0] = a;
                    hg[1] = tempk - a;
                }
                else
                {
                    hg[0] = tempk;
                    hg[1] = 0;
                }

                cout << fixed << setprecision(3) << hg[0] << " " << hg[1] << " 0.000 0.000\n";

                return 0;
            }
        }

        else
        {
            hg[0] = c;
            hg[1] = c;

            tempk = k;
            tempk -= 2.0 * c;

            if(tempk >= b)
            {
                hg[2] = b;
                hg[3] = tempk - b;
            }
            else
            {
                hg[2] = tempk;
                hg[3] = 0;
            }

            cout << fixed << setprecision(3) << hg[0] << " " << hg[1] << " " << hg[2] << " " << hg[3] << endl;

            return 0;
        }
    }
    if(cs == 1)
    {
        if(k > 4.0 * c)
        {
            evt = k / 4.0;

            cout << fixed << setprecision(3) << evt << " " << evt << " " << evt << " " << evt << endl;

            return 0;
        }

        if(3.0 * c >= k)
        {
            if(b * 3.0 <= k)
            {
                evt = k / 3.0;

                cout << fixed << setprecision(3) << evt << " " << evt << " " << evt << " 0.000\n";

                return 0;
            }

            else
            {
                tempk = k;

                if(tempk >= b)
                {
                    hg[0] = b;
                    tempk -= b;

                    if(2 * a <= k)
                    {
                        hg[1] = tempk / 2.0;
                        hg[2] = tempk / 2.0;
                    }

                    else if(tempk >= a)
                    {
                        hg[1] = a;
                        tempk -= a;

                        hg[2] = tempk;
                    }

                    else
                    {
                        hg[1] = tempk;
                        hg[2] = 0;
                    }
                }
                else
                {
                    hg[0] = tempk;
                    hg[1] = 0;
                    hg[2] = 0;
                }

                cout << fixed << setprecision(3) << hg[0] << " " << hg[1] << " " << hg[2] << " 0.000\n";

                return 0;
            }
        }

        else
        {
            hg[0] = c;
            hg[1] = c;
            hg[2] = c;

            tempk = k;
            tempk -= 3.0 * c;

            hg[3] = tempk;

            cout << fixed << setprecision(3) << hg[0] << " " << hg[1] << " " << hg[2] << " " << hg[3] << endl;

            return 0;
        }
    }
    if(cs == 2)
    {
        if(k > 4.0 * c)
        {
            evt = k / 4.0;

            cout << fixed << setprecision(3) << evt << " " << evt << " " << evt << " " << evt << endl;

            return 0;
        }

        if(2.0 * c >= k)
        {
            if(k / 2.0 >= a)
            {
                evt = k / 2.0;

                cout << fixed << setprecision(3) << evt << " " << evt << " 0.000 0.000\n";

                return 0;
            }

            else
            {
                tempk = k;

                if(tempk >= b)
                {
                    hg[0] = b;
                    hg[1] = tempk - b;
                }
                else
                {
                    hg[0] = tempk;
                    hg[1] = 0;
                }

                cout << fixed << setprecision(3) << hg[0] << " " << hg[1] << " 0.000 0.000\n";

                return 0;
            }
        }

        else
        {
            hg[0] = c;
            hg[1] = c;

            tempk = k;
            tempk -= 2.0 * c;

            if(a * 2.0 <= tempk)
            {
                hg[2] = tempk / 2;
                hg[3] = tempk / 2;
            }

            else if(tempk >= a)
            {
                hg[2] = a;
                hg[3] = tempk - a;
            }

            else
            {
                hg[2] = tempk;
                hg[3] = 0;
            }

            cout << fixed << setprecision(3) << hg[0] << " " << hg[1] << " " << hg[2] << " " << hg[3] << endl;

            return 0;
        }
    }

    if(cs == 3)
    {
        if(k > 4.0 * c)
        {
            evt = k / 4.0;

            cout << fixed << setprecision(3) << evt << " " << evt << " " << evt << " " << evt << endl;

            return 0;
        }

        tempk = k;
        if(c < tempk)
        {
            hg[0] = c;
            tempk -= c;

            if(2.0 * b >= tempk)
            {
                hg[3] = 0;
                if(2.0 * a >= tempk)
                {
                    hg[1] = a;
                    hg[2] = a;

                    cout << fixed << setprecision(3) << hg[0] << " " << hg[1] << " " << hg[2] << " " << hg[3] << endl;

                    return 0;
                }

                else
                {
                    if(a > tempk)
                    {
                        hg[1] = a;
                        hg[2] = tempk - a;

                    }

                    else
                    {
                        hg[1] = tempk;
                        hg[2] = 0;
                    }

                    cout << fixed << setprecision(3) << hg[0] << " " << hg[1] << " " << hg[2] << " " << hg[3] << endl;

                    return 0;
                }
            }
            else
            {
                hg[1] = b;
                hg[2] = b;
                hg[3] = tempk - 2.0 * b;

                cout << fixed << setprecision(3) << hg[0] << " " << hg[1] << " " << hg[2] << " " << hg[3] << endl;

                return 0;
            }
        }
    }
}

