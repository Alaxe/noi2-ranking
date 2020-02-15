#include <bits/stdc++.h>
using namespace std;
string s1, s2;
bool bukvi[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s1;
    for(int i = 0; i < s1.size(); i++)
    {
        bukvi[s1[i] - 'A'] = true;
    }
    bool bl = false;
    char dokyde = 'A';
    s2 = s1;
    for(int i = 0; i < 26; i++)
    {
        bl = false;
        if(bukvi[i])
        {
            for(int j = 0; j < s1.size(); j++){
                if(s1[j] == 'A' + i)
                {
                    s1[j] = dokyde;
                    bl = true;
                }
            }
            if(bl)
            {
                dokyde++;
            }
        }
    }
    cout << s1 << endl;
    dokyde = 'Z';
    for(int i = 0; i < 26; i++)
    {
        bl = false;
        for(int j = 0; j < s2.size(); j++)
        {
            if(s2[j] == 'Z' - i)
            {
                s2[j] = dokyde;
                bl = true;
            }
        }
        if(bl)
        {
            dokyde--;
        }
    }
    cout << s2;
    return 0;
}
