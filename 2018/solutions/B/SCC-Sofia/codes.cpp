#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, K, A, B;
vector <char> digits;
vector <string> seq;
vector <int> digitsRazl;

string generatee(vector <string> prev)
{
    string maxx = "0";
    int idx = 0;
    for (int i = 0; i < digits.size(); ++i)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < prev.size(); ++j)
            {
                if (idx < seq.size())
                {
                    seq[idx] = digits[i] + prev[j];
                }
                else
                {
                    seq.push_back(digits[i] + prev[j]);
                }
                if (idx >= A and idx <= B and seq[idx] > maxx)
                {
                    maxx = seq[idx];
                }
                ++idx;
            }
        }
        else
        {
            for (int j = prev.size() - 1; j >= 0; --j)
            {
                if (idx < seq.size())
                {
                    seq[idx] = digits[i] + prev[j];
                }
                else
                {
                    seq.push_back(digits[i] + prev[j]);
                }
                if (idx >= A and idx <= B and seq[idx] > maxx)
                {
                    maxx = seq[idx];
                }
                ++idx;
            }
        }
    }

    return maxx;
}

int main ()
{
    cin >> N >> K >> A >> B;
    --A;
    --B;

    for (int i = 0; i < N; ++i)
    {
        char curr;
        cin >> curr;

        digits.push_back(curr);

        string str = "";
        str += curr;
        seq.push_back(str);

        if (i > 0)
        {
            digitsRazl.push_back(abs(digits[i] - digits[i - 1]));
            //cout << digitsRazl[digitsRazl.size() - 1] << ' ';
        }
    }
    //cout << '\n';

    string maxNum = "0";
    for (int i = 1; i < K; ++i)
    {
        maxNum = max(maxNum, generatee(seq));
    }

    int maxRazl = -1;
    for (int i = A; i < B and (i == A or i % N != A % N); ++i)
    {
        //cout << maxRazl << '\n';
        if (i % N != N - 1)
        {
            //cout << "a " << i << '\n';
            if (digitsRazl[i % N] > maxRazl)
            {
                maxRazl = digitsRazl[i % N];
            }
        }
        else
        {
            int sum1 = 0;
            for (int j = 0; j < seq[i].size(); ++j)
            {
                sum1 += seq[i][j] - '0';
            }
            int sum2 = 0;
            for (int j = 0; j < seq[i + 1].size(); ++j)
            {
                sum2 += seq[i + 1][j] - '0';
            }
            sum1 = abs(sum1 - sum2);
            if (sum1 > maxRazl)
            {
                maxRazl = sum1;
            }
        }
    }

    cout << maxNum << ' ' << maxRazl << '\n';

    /*for (int i = 0; i < seq.size(); ++i)
    {
        cout << seq[i] << " (" << sum[i] << ") ";
    }
    cout << "\n";*/

    return 0;
}
