#include <iostream>
#include <string>

using namespace std;

string expr;
int s=0;

int main(){
  bool fl = true;
  cin >> expr;
  for (int i=0;i<expr.length() && fl;i++){
    if (expr[i] == '('){
      s++;
      if ((expr[i+1] != '(') && (expr[i+1] != '&'))
        fl = false;
    }
    if (expr[i] == ')') {
      s--;
      if (s<0) fl=false;
      if ((expr[i+1]=='(') || (expr[i+1]=='&'))
          fl=false;
    }
  }
  if (s!=0) fl=false;
  if (fl)
    cout << "Yes";
  else
    cout << "No";


return 0;
}
