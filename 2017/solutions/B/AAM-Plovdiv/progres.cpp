#include <iostream>
using namespace std;

int N[1028];

int main ()
{
    int n, a, br = 0, len = 0, d = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        N[i] = a;
    }

    for(int i = 0; i < n - 1; i++)
    {
        len = 0;
        d = 0;
        for(int j = i + 1; j < n; j++)
        {
            d = N[j] - N[i];
            if(N[i]  < N[j]) br++;
            for(int l = j + 1; l < n; l++)
            {
                if(N[l] - N[j] == d) len++;
            }
        }
        if(len > 0) br ++;

    }
    cout << br << endl;
    return 0;
}
