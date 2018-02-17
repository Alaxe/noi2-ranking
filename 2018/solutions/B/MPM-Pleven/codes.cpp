#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<string> generate(vector<string> prev, vector<string> digits) {
    vector<string> next;
    for(int i = 0; i < digits.size(); i++) {
        if (i % 2 == 0) {
            for(int j = 0; j < prev.size(); j++) {
                next.push_back(digits[i] + prev[j]);
            }
        } else {
            for(int j = prev.size() - 1; j >= 0; j--) {
                next.push_back(digits[i] + prev[j]);
            }
        }
    }
    return next;
}

long long sumDig(string s) {
    long long sum = 0;
    for(long long i = 0; i < s.length(); i++) {
        sum += s[i] - '0';
    }
    return sum;
}

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
    long long n, k, a, b, i, cu;
    cin >> n >> k >> a >> b;
    a--;
    b--;
    vector<string> digits;
    string e;
    for(i = 0; i < n; i++) {
        cin >> e;
        digits.push_back(e);
    }
    vector<string> v;
    v = digits;
    for(i = 0; i < k - 1; i++) {
        v = generate(v, digits);
    }

    long long max1 = abs(sumDig(v[a]) - sumDig(v[a + 1]));
    for(i = a; i < b; i++) {
        cu = abs(sumDig(v[i]) - sumDig(v[i + 1]));
        if (cu > max1) {
            max1 = cu;
        }
    }
    string ms = v[a];
    for(i = a + 1; i <= b; i++) {
        if (bStr(v[i], ms) == 1) {
            ms = v[i];
        }
    }
    cout << ms << " " << max1 << endl;
}
