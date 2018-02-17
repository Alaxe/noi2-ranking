#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (1 << 20);

int d;
string s;

void read()
{
    cin >> s;
}

int get(char x) { if(x >= '0' && x <= '9') return x - '0'; return x - 'A' + 10; }
char norm(int x) { if(x >= 0 && x <= 9) return x + '0'; return x - 10 + 'A'; }

void solve()
{
    string answer = "-1";
    int n = s.size();
    for(int last = 1; last < d; last++)
    {
        string curr = "";

        int carry = 0, l = last, pos_s = n - 1;
        while(pos_s >= 0)
        {
            int sum = l - get(s[pos_s]) - carry;

            carry = 0;
            while(sum < 0)
                sum += d, carry++;

            curr += norm(sum % d);
            l = sum % d;

            pos_s--;
        }

        while(carry != 0 || (l != last))
        {
            int sum = l - carry;

            carry = 0;
            while(sum < 0)
                sum += d, carry++;

            curr += norm(sum % d);
            l = sum % d;

            if(curr.size() > (int)5e4)
            {
                curr += "-";
                break;
            }
        }

        if(curr[curr.size() - 1] == '-' || get(curr[curr.size() - 1]) != last) continue;
        reverse(curr.begin(), curr.end());

        if(answer == "-1") answer = curr;
        else if(answer.size() > curr.size()) answer = curr;
        else if(answer.size() == curr.size()) chkmin(answer, curr);
    }

    if(answer == "-1") answer = "0";
    cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T = 4;
    cin >> d;

    while(T--)
    {
        read();
        solve();
    }

	return 0;
}
