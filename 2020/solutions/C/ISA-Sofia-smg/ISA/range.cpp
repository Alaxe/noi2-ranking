#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int posicii[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    sort(arr, arr + n);
    int a = 0, b = 0;
    posicii[arr[0]] = 0;
    for(int i = 1; i < n; i++)
    {
        if(posicii[arr[i]] == 0)
        {
            posicii[arr[i]] = i;
        }
    }
    int posa, posb;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if(a > arr[n - 1])
        {
            cout << 0;
        }
        else
        {
            if(posicii[a] != 0 || a == arr[0])
            {
                posa = posicii[a];
            }
            else
            {
                for(int j = a + 1; j <= arr[n - 1]; j++)
                {
                    if(posicii[j] > 0 || j == arr[0])
                    {
                        posa = posicii[j];
                        break;
                    }
                }
            }
            if(posicii[b] != 0 || b == arr[0])
            {
                posb = posicii[b];
            }
            else
            {
                for(int j = b - 1; j >= 0; j--)
                {
                    if(posicii[j] > 0 || b == arr[0])
                    {
                        posb = posicii[j];
                        break;
                    }
                }
            }
            cout << posb - posa + 1 << endl;
        }
    }
    return 0;
}
