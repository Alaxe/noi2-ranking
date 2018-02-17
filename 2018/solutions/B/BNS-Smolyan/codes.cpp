#include <bits/stdc++.h>

using namespace std;

int n, k, a, b;

int getSum(string c)
{
    int s = c[0] - '0';
    for(int i = 1; i < c.length(); i++)
    {
       s += c[i] - '0';
    }
    return s;
}
int getNumber(string c)
{
    int s = c[0] - '0';
    for(int i = 1; i < c.length(); i++)
    {
        s *= 10; s += c[i] - '0';
    }
    return s;
}

vector <string> generate(vector <string> prev, vector <char> digits)
{
    vector <string> next;
    for(int i = 0; i < digits.size(); i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < prev.size(); j++)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
        else
        {
            for(int j = prev.size() - 1; j >= 0; j--)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
    }
    return next;
}

int main()
{
    scanf("%d %d %d %d", &n, &k, &a, &b);
    vector <string> prev;
    vector <char> digits;
    for(int i = 0; i < n; i++)
    {
        int c;
        scanf("%d", &c);
        char temp = c + '0';
        digits.push_back(temp);
        string j = "";
        prev.push_back(j + temp);
    }

    for(int i = 0; i < k - 1; i++)
    {
        prev = generate(prev, digits);
    }
    int ans = 0, biggest = getNumber(prev[b - 1]);
    for(int i = a - 1; i < b - 1; i++)
    {
        biggest = max(getNumber(prev[i]), biggest);
        ans = max(ans, abs(getSum(prev[i]) - getSum(prev[i + 1])));
    }

    printf("%d %d\n", biggest, ans);

    return 0;
}

/*
3 2 3 5
7 1 5

75 6
*/

/*
3 3 10 16
7 1 5

175 6
*/
