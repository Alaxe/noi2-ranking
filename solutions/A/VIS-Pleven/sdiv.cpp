#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string seq;
int n , m;

int recursion (string s)
{
    if (s.size() == 0)
    {
        return 0;
    }
    int ans = 0;
    int currentNum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        currentNum = currentNum * 10 + s[i];
        currentNum %= n;
        if (currentNum == 0)
        {
            ans++;
        }
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        string s1 = "";
        for (int j = 0; j < s.size(); j++)
        {
            if (i == j) continue;
            s1 += s[j];
        }
        ans += recursion (s1);
    }

}

int main()
{
    int ans = 0;
    cin >> seq;
    cin >> n >> m;
    int seqSize = seq.size();

    ans = recursion(seq);

    cout << ans << endl;

    return 0;
}
