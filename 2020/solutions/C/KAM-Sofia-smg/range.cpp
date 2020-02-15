#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int m;
    cin >> m;
    int a, b, range_begin = 0, range_end = 0, last_itr = n / 2;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        range_begin = 0;
        range_end = 0;
        ///range_begin
        for(int j = 0; true;)
        {
            if(arr[n - 1] < a)
                break;
            if(arr[0] >= a)
                break;
            if(last_itr < 1)
                last_itr = 1;
            if(arr[j] >= a && (j == 0 || arr[j - 1] < a))
            {
                range_begin = j;
                break;
            }
            else if(arr[j] < a)
            {
                j += last_itr;
                last_itr /= 2;
            }
            else if(arr[j] >= a && arr[j - 1] >= a)
            {
                j -= last_itr;
                last_itr /= 2;
            }
        }
        last_itr = n / 2;
        ///range_end
        for(int j = 0; true;)
        {
            if(arr[n - 1] <= b)
            {
                range_end = n - 1;
                break;
            }
            if(arr[0] > b)
                break;
            if(last_itr < 1)
                last_itr = 1;
            if(arr[j] <= b && (j == n - 1 || arr[j + 1] > b))
            {
                range_end = j;
                break;
            }
            else if(arr[j] <= b && arr[j + 1] <= b)
            {
                j += last_itr;
                last_itr /= 2;
            }
            else if(arr[j] > b)
            {
                j -= last_itr;
                last_itr /= 2;
            }

        }
        last_itr = n / 2;
        if(arr[0] > b || arr[n - 1] < a)
            cout << 0 << endl;
        else
            cout << range_end - range_begin + 1 << endl;

    }





    return 0;
}
