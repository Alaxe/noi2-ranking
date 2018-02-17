#include <iostream>
#include <vector>

using namespace std;

const long long max_sum = 1000*1000;
const long long min_sum = -1000*1000;
const long long size = max_sum - min_sum + (1 << 10);

long long arr [1024];
bool knapsack [size];

int main ()
{
    cin.tie (NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> arr [i];
    }

    knapsack [0 - min_sum] = true;

    long long ans = 0;

    int bonus = -1;
    for (int i = 0 ; i < n ; i ++)
    {
        vector <long long> new_sums;
        for (long long j = size - arr [i] ; j >= 0 ; j --)
        {
            if (knapsack [j])
            {
                if (j + arr [i] == 0 - min_sum)
                    bonus = 0;
                if (!knapsack [j + arr [i]])
                    new_sums.push_back (j + arr [i]);
            }
        }
        for (long long j = 0 ; j < new_sums.size () ; j ++)
        {
            knapsack [new_sums [j]] = true;
        }
    }
    for (long long i = 0 ; i < size ; i ++)
    {
        ans += knapsack [i];
    }
    cout << ans + bonus << "\n";
}
