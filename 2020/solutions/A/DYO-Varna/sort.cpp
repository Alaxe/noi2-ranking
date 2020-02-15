#include <iostream>
#define endl '\n'
using namespace std;

#define NMax 1000
#define VMax 10000

int n, arr[NMax + 2], minv = VMax, maxv = 0;
int dp[VMax + 2][NMax + 2], minprow[VMax + 2];

int modul(int a)
{
    if(a < 0) return -a;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> arr[i];
        if(arr[i] < minv) minv = arr[i];
        if(arr[i] > maxv) maxv = arr[i];
    }

    for(int j = 0; j < n; j ++)
    {
        for(int i = minv; i <= maxv; i ++)
        {
            if(j == 0)
            {
                dp[i][j] = modul(arr[j] - i);
                if(i != minv) minprow[i] = min(minprow[i - 1], dp[i][j]);
                else minprow[i] = dp[i][j];
                continue;
            }
            else if(i == minv)
            {
                dp[i][j] = modul(arr[j] - i) + dp[i][j - 1];
                minprow[i] = dp[i][j];
                continue;
            }

            dp[i][j] = modul(arr[j] - i) + minprow[i];
            minprow[i] = min(minprow[i - 1], dp[i][j]);
        }
    }

    cout << minprow[maxv] << endl;

    return 0;
}
