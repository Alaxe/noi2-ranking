#include <iostream>
#include <map>
#include <string>
using namespace std;

string s;
const int MAX_N = 2e5+7;
int ids[MAX_N];
bool should_be_removed[MAX_N];

int findClosingIndex(int i) {
    int id = ids[i];
    for(int j = i + 1; j < s.length(); j ++) {
        if(ids[j] == id) {
            return j;
        }
    }
}

int get_priority(char op) {
    if(op == '+') return 1;
    if(op == '-') return 1;
    if(op == '*') return 2;
    if(op == '/') return 2;
}

int min_priority_of_op_in_brackets(int start, int end) {
    int min_pr = 10;
    for(int i = start + 1; i < end; i ++) {
        int curr_pr = 10;
        if(s[i] == '&') continue;
        else if(s[i] == '(') i = findClosingIndex(i);
        else if(s[i] == ')') continue;
        else curr_pr = get_priority(s[i]);
        if(curr_pr < min_pr) min_pr = curr_pr;
    }
    return min_pr;
}

bool are_brackets_useless(int start, int end) {
    int inside = min_priority_of_op_in_brackets(start, end);
    if(inside == 10) return true;

    char before;
    char after;
    if(start - 1 < 0 || s[start - 1] == '(') {
        before = '+';
    }
    else before = s[start - 1];
    if(end + 1 >= s.length() || s[end + 1] == ')') {
        after = '+';
    }
    else after = s[end + 1];

    if(before == '/') return false;
    else if(before == '*') {
        if(inside == 1) return false;
        else if(inside == 2) return true;
    }
    else if(before == '-') {
        if(inside == 2) return true;
        else if(inside == 1) return false;
    }
    else if(before == '+') {
        if(inside == 2) return true;
        else if(inside == 1) {
            if(get_priority(after) == 1) return true;
            else if(get_priority(after) == 2) return false;
        }
    }
}

int main() {
    cin >> s;
    int balance = 1;
    for(int i = 0; i < s.length(); i ++) {
        if(s[i] == '(') {
            ids[i] = balance;
            balance ++;
        }
        else if(s[i] == ')') {
            balance --;
            ids[i] = balance;
        }
    }
    for(int i = 0; i < s.length(); i ++) {
        if(s[i] == '(') {
            int j = findClosingIndex(i);
            if(are_brackets_useless(i, j)) {
                should_be_removed[i] = true;
                should_be_removed[j] = true;
            }
        }
        if(!should_be_removed[i]) cout << s[i];
    }
    cout << endl;
}
