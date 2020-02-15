#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

string input;
int sizeInput = 0;


bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
    if (lhs.second - lhs.first == rhs.second - rhs.first) {
        return lhs.first < rhs.first;
    }
    return lhs.second - lhs.first < rhs.second - rhs.first;
}

bool canDeleteBrackets(pair<int, int> currBrackets) {
    bool hasPlus = false;
    bool hasMinus = false;
    bool hasMult = false;
    bool hasDiv = false;
    int isPlusInUse = 0;
    for (int i = currBrackets.first + 1; i < currBrackets.second; ++ i) {
        if (input[i] == '(') {
            ++ isPlusInUse;
        }
        if (input[i] == ')') {
            -- isPlusInUse;
        }
        if (isPlusInUse == 0 && input[i] == '-') {
            hasMinus = true;
        }
        if (isPlusInUse == 0 && input[i] == '+') {
            hasPlus = true;
            break;
        }
        if (isPlusInUse == 0 && input[i] == '*') {
            hasMult = true;
            break;
        }
        if (isPlusInUse == 0 && input[i] == '/') {
            hasDiv = true;
            break;
        }
    }
    ///If the first sign after the 2 bracket is /
    if (input[currBrackets.second + 1] == '/') {
        for (int i = currBrackets.second - 1; i >= 0; -- i) {
            if (input[i] == '&' || input[i] == '|') {
                continue;
            }
            if (input[i] != '/') {
                return true;
            }
        }
        return false;
    }
    ///If there is no plus or minus
    if (!hasPlus && !hasMinus) {
        if (currBrackets.first - 1 >= 0) {
            if (input[currBrackets.first - 1] == '*' && hasDiv) {
                return false;
            }
            if (input[currBrackets.first - 1] == '/' && hasMult) {
                return false;
            }
        }
        return true;
    }
    ///Only for the plus
    for (int i = currBrackets.first - 1; i >= 0; -- i) {
        if (input[i] == '(' || input[i] == '+') {
            break;
        }
        if (input[i] == '*' || input[i] == '/') {
            return false;
        }
    }
    for (int i = currBrackets.second + 1; i < sizeInput; ++ i) {
        if (input[i] == ')' || input[i] == '+') {
            break;
        }
        if (input[i] == '*' || input[i] == '/') {
            return false;
        }
    }
    ///Now for the minus
    for (int i = currBrackets.first - 1; i >= 0; -- i) {
        if (input[i] == '(' || input[i] == '+') {
            break;
        }
        if (input[i] == '*' || input[i] == '/' || input[i] == '-') {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool onlyPlus = true;
    bool onlyMult = true;
    bool onlyMinus = true;
    bool onlyDiv = true;
    vector<pair<int, int> > brackets;
    priority_queue<int> positionBrackets;

    cin >> input;
    sizeInput = input.size();
    for (int i = 0; i < sizeInput; ++ i) {
        if (input[i] == '(') {
            positionBrackets.push(i);
        }
        if (input[i] == ')') {
            int firstBracket = positionBrackets.top();
            positionBrackets.pop();
            brackets.push_back(make_pair(firstBracket, i));
        }
    }
    sort(brackets.begin(), brackets.end(), cmp);
    for (int i = 0; i < brackets.size(); ++ i) {
        if (canDeleteBrackets(brackets[i])) {
            input[brackets[i].first] = '|';
            input[brackets[i].second] = '|';
        }
    }
    for (int i = 0; i < sizeInput; ++ i) {
        if (input[i] == '|') {
            continue;
        }
        cout << input[i];
    }
    cout << endl;
    return 0;
}
