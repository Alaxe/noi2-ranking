/**
NOI2018-2
Group : E
Task  : flowers
Author: E.Vassilev
*/
#include <iostream>
using namespace std;
int main () {
  long long n, q, h, i=0, max_h=0, sum_h=0;

  cin >> n;
  while ( i<n ){
    cin >> h;
    if (h>max_h) max_h=h;
    sum_h+=h;
    i++;
  }
  cin >> q;
  cout << (n*max_h - sum_h)*q << endl;
  return 0;
}
/** Var. 2
#include <iostream>
using namespace std;
long long n, max_h, h, sum_h, i;
int main () {
  for (cin >> n; i<n; i++, sum_h+=(h>max_h?max_h=h:h)) cin >> h;
  cin >> h;  /// h as q
  cout << (n*max_h - sum_h) * h << endl;
  return 0;
}
*/

/**
input
5
10 20 17 12 20
25
output
525
*/
