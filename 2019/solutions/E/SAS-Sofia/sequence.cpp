#include <iostream>
using namespace std;
int main () {
  long long n, a;
  cin >> n;
  if (n == 1 or n == 2) {
    a = n + (n - 1);
    cout << a <<endl;
  }else {
    a = n + (n + 1);
    cout << a <<endl;
  }

}
