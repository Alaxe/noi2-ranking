#include <iostream>

using namespace std;

string trStr(string s) {
    int index = 0;
    string n = "";
    for(int i =0; i <s.length(); i++) {
        if(s[i] != '0') {
            index = i;
            break;
        }
    }
    for(int i =index; i <s.length(); i++) {
        n += s[i];
    }
    return n;
}

bool bStr(string s1, string s2) {
    if (s1[0] == '0') s1 = trStr(s1);
    if (s2[0] == '0') s2 = trStr(s2);
    if (s1.length() == s2.length()) {
        return s1 > s2;
    }
    return s1.length() > s2.length();
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << bStr(s1, s2) <<endl;
    return 0;
}
