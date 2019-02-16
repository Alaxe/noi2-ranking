#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, m, n;
    cin >> k >> m >> n;
    if (k < 0 || m < 0 || n < 0 || k > 50 || m > 50 || n > 50)
    {
        cout << endl << endl << "Unexpected number entered" << endl << endl;
        return 0;
    }

    int redici = 0;
    int redica[n];
    //for (int i = 1; i <= n; i++)
    //{
        for (int f = 1; f < m; f++)
        {
            for (int g = 0; g < n; g++)
            {
                redica[g] = 0;
            }
            redica[0] = f;
            for(int h = 1; h <= n; h++)
            {
                for (int task3 = 0; task3 < 2; task3++)
                {
                    if (task3 == 1)
                    {
                        if ((redica[h-1] + k) < m)
                        {
                            redica[h] = redica[h-1] + k;
                        }
                    } else if (task3 == 0) {
                        if ((redica[h-1] - k) > 0)
                        {
                            redica[h] = redica[h-1] - k;
                        }
                    }
                    for (int g = 0; g < n; g++)
                    {
                        if (redica[g] <= 0 || redica[g] >= m)
                            continue;
                    }
                    redici++;
                }
            }
        }
    //}
    redici = redici / 2 / k;
    cout << redici << endl;

}
