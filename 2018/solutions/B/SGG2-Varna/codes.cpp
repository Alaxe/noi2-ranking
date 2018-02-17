#include <bits/stdc++.h>
using namespace std;

unsigned long long i, j;

vector<string> next;
vector<string> generate(vector<string> prev, vector<char> digits)
{
    for (i = 0; i < digits.size(); ++i)
    {
        if (i%2 == 0)
        {
            for (j = 0; j < prev.size(); ++j)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
        else
        {
            for (j = prev.size() - 1; j >= 0; --j)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
    }
}

unsigned long long to_int(string k)
{
    ///string k = "999111333";
    unsigned long long ans(0), sz = pow(10, k.size()-1) + 1;
    for (i = 0; i < k.size(); ++i)
    {
        ans += ((k[i]-'0')*sz);
        sz/=10;
    }
    return ans;
}

int main(void)
{
    unsigned int N, K;
    unsigned long long A, B, numMAX;
    cin >> N >> K >> A >> B;

    vector<string> prev;//, curr;
    vector<char> digits;
    char temp;

    for (i = 0; i < N; ++i)
    {
        cin >> temp;
        digits.push_back(temp);
    }

    for (i = 0; i < (K-1); ++i) /// първата редица е дадена
        generate(prev, digits);

    for (i = 0; i < next.size(); ++i)
        cout << next[i] << '\n';

    vector<unsigned long long> v;
    for (i = (A-1); i < (B-1); ++i) /// човешко броене
        v.push_back(to_int(next[i]));

    for (i = 1; i < v.size(); ++i)
        numMAX = max(v[i-1], v[i]);

    cout << numMAX << '\n';
    return 0;

}
/**
3 2 3 5
7 1 5
*/
