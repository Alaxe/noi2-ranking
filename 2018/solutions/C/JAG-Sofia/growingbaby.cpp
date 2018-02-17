#include <iostream>
using namespace std;
const int a = 1100000000;
int main()
 {
  int  M , N , p , q , rezultat , razlika;
  cin >> M >> N >> p >> q;
  razlika = N - M;
  rezultat = ( razlika / p ) * ( p/q+1 ) - 1 ;
  cout << rezultat;

  return 0;
 }
