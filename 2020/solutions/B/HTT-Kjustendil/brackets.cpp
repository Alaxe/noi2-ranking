#include <iostream>
#include <stack>
#include <set>
using namespace std;

int n;
int currIndex;
set<char> operators;

string parser(string s , int index) {

    string expr;
    set<char> op;
    currIndex = index;

    while(1) {
        if(s[currIndex]=='(') {
            expr += parser(s, currIndex+1);
        }else if(s[currIndex] == ')') {
          if((s[currIndex+1] != '*') && (s[currIndex+1] != '/')){
              return expr;
          }else {
              if ((op.find('+') == op.end()) && (op.find('-') == op.end())) {
                  return expr;
              }else {
                  return '('+expr+')';
              }
          }
        }else {
            char temp = s[currIndex];
            expr=expr+temp;
            if(operators.find(temp) != operators.end()) {
                op.insert(temp);
            }
        }
        currIndex++;
        if(currIndex >= n) {
            break;
        }
    }
    return expr;
}

int main() {

    string s;
    cin >> s;

    n = s.size();

    operators.insert('+');
    operators.insert('-');
    operators.insert('*');
    operators.insert('/');

    cout<<parser(s,0)<<endl;;

    return 0;
}
