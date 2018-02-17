#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string substring (string s, int i, int j)
{
    string res = "";
    for (i; i <= j; i++) {
        res = res + s[i];
    }
    return res;
}

long long palCalc(string current) {
    if (current == "") {
        return 0;
    }
    long long cnt = current.size();
    for (int i = 0; i < current.size() - 1; i++) {
        for (int j = i + 1; j < current.size(); j++)
        {
            if (current[i] == current[j]) {
                cnt++;
                cnt += palCalc(substring(current, i + 1, j - 1));
            }
        }
    }
    return cnt;

}

int main(){
    string input;
    cin >> input;

    long long palCount = 0;
    palCount = palCalc (input);
    cout << palCount;


    return 0;
}
