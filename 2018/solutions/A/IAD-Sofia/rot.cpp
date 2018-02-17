#include<iostream>
using namespace std;
int b;
string num[4];
int st[256];
char rev[18] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H'};
string ans;
int sum(string n)
{
    int res = 0;
    for(int i = 0; i < n.size(); i ++)
    {
        res += st[n[i]];
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
st['0'] = 0;
st['1'] = 1;
st['2'] = 2;
st['3'] = 3;
st['4'] = 4;
st['5'] = 5;
st['6'] = 6;
st['7'] = 7;
st['8'] = 8;
st['9'] = 9;
st['A'] = 10;
st['B'] = 11;
st['C'] = 12;
st['D'] = 13;
st['E'] = 14;
st['F'] = 15;
st['G'] = 16;
st['H'] = 17;
    cin >> b;
    cin >> num[0];
    cin >> num[1];
    cin >> num[2];
    cin >> num[3];
    for(int i = 0; i < 4; i ++)
    {
        num[i] = "0"+num[i];
        ans = "";
        int curr = 1;
        if(sum(num[i]) % (b-1) != 0) cout << "0\n";
        else
        {
            for(int j = num[i].size()-1; j >= 1; j --)
            {
                //cout << num[i][j] << " /\n";
                if(st[num[i][j]] > curr)
                {
                    ans += rev[curr-(st[num[i][j]]-b)];
                    curr = curr-(st[num[i][j]]-b);
                    num[i][j-1] = rev[st[num[i][j-1]]+1];
                }
                else
                {
                    ans += rev[curr-st[num[i][j]]];
                    curr = curr-st[num[i][j]];
                }
                //cout << curr << endl;
            }
            if(num[i][0] != '0') ans += num[i][0];
            for(int p = ans.size()-1; p >= 0; p --) cout << ans[p];
            cout << endl;
        }
    }
}
