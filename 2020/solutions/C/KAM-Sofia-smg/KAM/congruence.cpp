#include <bits/stdc++.h>
using namespace std;
int main()
{
    string word;
    cin >> word;
    string word_cpy = word;
    map<char, char> congmin, congmax;
    sort(word.begin(), word.end());
    char m = 'A', n = 'Z';
    int sz = word.size();
    for(int i = 0; i < sz; i++)
    {
        if(congmin[word[i]] == 0)
        {
            congmin[word[i]] = m;
            m++;
        }
    }
    for(int i = sz - 1; i >= 0; i--)
    {
        if(congmax[word[i]] == 0)
        {
            congmax[word[i]] = n;
            n--;
        }
    }
    for(int i = 0; i < sz; i++)
    {
        cout << congmin[word_cpy[i]];
    }
    cout << endl;
    for(int i = 0; i < sz; i++)
    {
        cout << congmax[word_cpy[i]];
    }
    cout << endl;







    return 0;
}
