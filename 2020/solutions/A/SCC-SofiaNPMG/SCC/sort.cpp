#include <iostream>

using namespace std;

int A[100000], n;
int Acopy[100000];

int solve (int idx, int sum)
{
    /*cout << idx << ' ' << sum << '\n';
    for (int i = 0; i < idx; ++i)
    {
        cout << A[i] << ' ';
    }
    cout << '\n';*/

    if (idx == n)
    {
        return sum;
    }

    if (A[idx] >= A[idx - 1])
    {
        //cout << "ostavi si go tata\n";
        return solve(idx + 1, sum);
    }
    else
    {
        //uvelichi
        int a = A[idx - 1] - A[idx];
        A[idx] = A[idx - 1];
        //cout << "uvelichi\n";
        a = solve(idx + 1, sum + a);
        A[idx] = Acopy[idx];

        //zapazi
        int b = 0, i;
        for (i = idx - 1; i >= 0 and A[i] > A[idx]; i--)
        {
            b += A[i] - A[idx];
            A[i] = A[idx];
        }

        if (b >= a)
        {
            for(; i < idx; ++i)
            {
                A[i] = Acopy[i];
            }

            return a;
        }

        //cout << "namali\n";
        b = solve(idx + 1, sum + b);
        for(; i < idx; ++i)
        {
            A[i] = Acopy[i];
        }

        return min(a, b);
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    bool isSorted = true;
    int maxx = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        Acopy[i] = A[i];

        if (i > 0 and A[i] < A[i - 1])
        {
            isSorted = false;
        }
    }

    if (isSorted)
    {
        cout << 0 << '\n';
        return 0;
    }

    cout << solve(1, 0) << '\n';

    return 0;
}

