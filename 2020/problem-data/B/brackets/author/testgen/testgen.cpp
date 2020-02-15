#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string expr,expr1;
string s1,s2,s3;
int m;

int main(){
  int n,k,x,y;
  srand(time(NULL));
  cin >> n; cin >> k;
  expr="&";
  for (int i=2;i<=n;i++){
    x=rand()%4+1;
    switch (x){
      case 1:expr=expr+"+";break;
      case 2:expr=expr+"-";break;
      case 3:expr=expr+"*";break;
      case 4:expr=expr+"/";break;
    }
    expr=expr+"&";
  }

  int i,j,pos;
  i=0;
  while (i<k){
    expr1=expr;
    x=rand()*rand()%(n-1)+1;
    y=x+1+rand()*rand()%(n-x);
    j=0;pos=0;
    while (j<x){
      if (expr[pos] == '&') j++;
      pos++;
    }
    pos--;
    if (expr[pos+1] != ')') {
       expr = expr.substr(0,pos)+"("+expr.substr(pos,expr.length()-pos);
       pos=pos+2;
       while (j<y){
         if (expr[pos] == '&') j++;
       pos++;
       }
       pos--;
       if (expr[pos-1] != '('){
          expr = expr.substr(0,pos+1)+")"+expr.substr(pos+1,expr.length()-pos-1);
          i++;
       }
       else
          expr=expr1;
    }
  }

  cout << expr << endl;

  return 0;
}
