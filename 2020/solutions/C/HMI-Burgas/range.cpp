#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int k = 0; k < n; k++)
        cin >> arr[k];

    int m;
    cin >> m;

    int zaqwki[m][2];
    for (int j = 0; j < m; j++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            return 1;
        zaqwki[j][0] = a;
        zaqwki[j][1] = b;
    }

    for(int i = 0; i < m; i++)
    {
        int numCount = 0;
        int a, b;
        a = zaqwki[i][0];
        b = zaqwki[i][1];
        for(int l = 0; l < n; l++)
            if (arr[l] >= a && arr[l] <= b)
                numCount++;
        cout << numCount << endl;
    }
    return 0;
}
