#include <iostream>
#include <string>
using namespace std;
string n;

bool compare(string s1, string s2)
{
    long long l1 = s1.size(), l2 = s2.size();

    if (l1 > l2)return 1;
    if (l1 < l2)return 0;

    for (int i = 0; i < l1; i++)
    {
        if (s1[i] > s2[i])return 1;
        if (s1[i] < s2[i])return 0;
    }

    return 0;
}

string ez()
{
    string s = "";
    if (n[0] != '9')
    {
        s += char(n[0] + 1);

        for (int i = 0; i < n.size() - 2; i++)
            s += "0";

        s += char(n[0] + 1);
    }
    else
    {
        s = "1";
        for (int i = 0; i < n.size() - 1; i++)
            s += "0";
        s += "1";
    }

    return s;
}

string cre1ate(string s)
{
    string s1 = s;

    for (int i = s.size() - 1; i >= 0; i--)
        s1 += s[i];

    return s1;
}

string cre0ate(string s, char p)
{
    string s1 = s + p;

    for (int i = s.size() - 1; i >= 0; i--)
        s1 += s[i];

    return s1;
}

string f1nd()
{
    long long l = n.size();
    long long y, start;
    string s = "";

    //if (n.size() % 2 == 0)
    //{
        start = n.size() / 2 - 1;
        y = n.size() / 2;
        for (int i = 0; i < n.size() / 2; i++)
            s += n[i];
    //}
    /*else
    {
        start = n.size() / 2 - 1;
        y = n.size() / 2 + 1;
        for (int i = 0; i < n.size() / 2; i++)
            s += n[i];
    }*/

    //cout << y << endl;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        //cout << s[i] << "-" << n[y] << endl;
        if (s[i] < n[y])
        {
            s[i] = n[y];
        }
        if (s[i] == n[y] && n[y] != '9')s[i] = char(n[i] + 1);
        if (compare(cre1ate(s), n))return cre1ate(s);
        y++;
    }

    // if n is a palindrome


    return "its a palindrome";
}

string f0nd()
{
    long long l = n.size();
    long long y, start;
    string s = "";

    start = n.size() / 2 - 1;
    y = n.size() / 2 + 1;
    for (int i = 0; i < n.size() / 2; i++)
        s += n[i];

    //cout << n.size() << endl;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        //cout << s[i] << "-" << n[y] << endl;
        if (s[i] < n[y])
        {
            s[i] = n[y];
        }
        if (s[i] == n[y] && n[y] != '9')s[i] = char(n[i] + 1);
        if (compare(cre0ate(s, n[n.size() / 2]), n))return cre0ate(s, n[n.size() / 2]);
        y++;
    }

    return "its a palindrome";
}

int main()
{
    cin >> n;

    if (n.size() == 1 && n != "9")
    {
        cout << char(n[0] + 1) << endl;
        return 0;
    }
    if (n == "9")
    {
        cout << 11 << endl;
        return 0;
    }

    //cout << n.size() << endl;
    if (n.size() % 2 == 0)
    {
        string s1 = f1nd();
        string s2 = ez();
        if (compare(s1, s2))cout << s2 << endl;
        else cout << s1 << endl;
        //cout << s1 << "-" << s2 << endl;
    }
    else
    {
        string s1 = f0nd();
        string s2 = ez();
        if (compare(s1, s2))cout << s2 << endl;
        else cout << s1 << endl;
        //cout << s1 << "-" << s2 << endl;
    }

    return 0;

}
