#include <iostream>
using namespace std;

int main () {

int chislo_Kris, chislo_Eva, naj_blizko_do_chislo_Kris, brojach=0;
cin >> chislo_Kris >> chislo_Eva;
int chuvani_chisla, suma_na_chetnite=0;

while (suma_na_chetnite <= chislo_Eva) {
    cin >> chuvani_chisla;
    if (chuvani_chisla % 2 == 0) {
        suma_na_chetnite = suma_na_chetnite + chuvani_chisla;
    }
}

cout << naj_blizko_do_chislo_Kris << suma_na_chetnite << endl;

return 0;
}
