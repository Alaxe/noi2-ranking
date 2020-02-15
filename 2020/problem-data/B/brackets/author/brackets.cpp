#include <iostream>
#include <string>

using namespace std;

const int len_max=200000;

string expr;
string expr1;
int br_to_remove[len_max+1];
int expr_uk=0;

int br_analyze(){
  /*
    Променливата res показва какви операции е имало "вътре" в скобите (за понятието "вътре" вижте анализа на задачата.
    res = 1 - в скобите има само + и -;
    res = 2 - в скобите има само * и /;
    res = 3 - в скобите има операции и от двата приоритета;
    res = 0 - все още не са се срещнали операции вътре в скобите;
    Функцията връща: 0,ако скобите не се премахват, или изчислената стойност на res,
                     ако скобите се премахват (в този случай операциите вътре в премахваните скоби
                     се "вдигат" на едно ниво и стават операции вътре в обхващащите скоби
                     от по-високото ниво)
  */
  int k;
  int res=0,res1;
  k=expr_uk;
  expr_uk++;
  while (expr[expr_uk]!=')'){
    if (expr[expr_uk]=='('){
       res1 = br_analyze();
       res=res|res1;
    }
    else {
       if (expr[expr_uk]=='+' || expr[expr_uk]=='-'){
          if(res < 2)
            res=1;
          else
            res=3;}
       else
          if (expr[expr_uk]=='*' || expr[expr_uk]=='/'){
            if ((res == 1) || (res == 3))
              res=3;
            else
              res=2;}
    }
    expr_uk++;
  }

  if (((expr[k-1]=='%') && (expr[expr_uk+1]!='*') && (expr[expr_uk+1]!='/')) ||
      ((expr[k-1]=='(') && (expr[expr_uk+1]!='*') && (expr[expr_uk+1]!='/')) ||
      ((expr[k-1]=='+') && (expr[expr_uk+1]!='*') && (expr[expr_uk+1]!='/')) ||
      ((expr[k-1]=='-') && ((res==2)||(res==0))) ||
      (((expr[k-1]=='*') || (expr[expr_uk+1]=='*')) && (expr[k-1]!='/') && ((res==2)||(res==0))) ||
      ((expr[k-1]!='/') && (expr[expr_uk+1]=='/') && ((res==2)||(res==0))))

  {
      br_to_remove[k]=1;
      br_to_remove[expr_uk]=1;
  }
  else
    res=0;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  for (int i=0;i<=len_max;i++)
    br_to_remove[i]=0;

  cin >> expr;

  expr = "%"+expr+"%";
  expr_uk=1;
  while (expr[expr_uk]!='%'){
    if (expr[expr_uk]=='(')
       br_analyze();
    expr_uk++;
  }
  for (int i=1;i<expr.size()-1;i++)
    if (br_to_remove[i]==0)
       cout << expr[i];
  cout << endl;
  return 0;
}

/*
&*(&+&*(&*&)+&*&)
*/


