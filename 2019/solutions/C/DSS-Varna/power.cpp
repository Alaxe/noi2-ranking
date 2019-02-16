#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct deliteli
{
    int a, br;
};

int n, k, a[11000] = {0}, pr[14] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}, j = 0, otg = 1;
deliteli lmao[14];

int main()
{
    cin >> n >> k;

    lmao[0].a = 2;
    lmao[0].br = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        j = 0;
        while(a[i] > 1)
        {
            while(a[i] % pr[j] != 0)
            {
                j++;
                lmao[j].a = pr[j];
                lmao[j].br = 0;
            }

            a[i] /= pr[j];
            lmao[j].br++;
        }
    }



    j = 0;
    for(int i = 0; i < 14; i++)
    {
        if(lmao[i].br == 0) continue;
        if(lmao[i].br % k != 0) j = 1;

        lmao[i].br = lmao[i].br / k + j;

        while(lmao[i].br > 0)
        {
            otg *= lmao[i].a;
            lmao[i].br--;
        }
    }

    cout << otg << endl;
}
