#include <iostream>
using namespace std;

int main()
{
    int n,z,m,br,ch1;
    int max1 = 0;
    int j1,i1;
    br = 1;
    int ch;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n / 2; j++)
        {
            ch = i * j;
            ch1 = ch;
            while (ch1 > 0)
            {
                ch1 = ch1 / 10;
                br = br * 10;
            }
            cout << ch << endl;
            while (ch > 0)
            {
                z = ch % 10;
                ch = ch / 10;
                m = z * br;
                if (m > max1)
                {
                    max1 = m;
                    j1 = j;
                    i1 = i;
                }
                br = br / 10;
            }
        }
    }
    cout << max1 << endl;

}
