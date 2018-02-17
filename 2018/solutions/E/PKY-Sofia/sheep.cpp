#include <iostream>
using namespace std;
int main() {

    long long n, l;
    bool is_this_number_correct = true;
    cin >> n >> l;
    int missing_digits[l], numbers_so_far_that_are_correct = 0, number_for_checking;
    for (int i = 0; i < l; i++) {       //cin-ва всички липсващи печати
        cin >> missing_digits[i];
    }

    for (number_for_checking = 1; numbers_so_far_that_are_correct < n; number_for_checking++) {     //цикъл, който започва ot 1 и спира когато сме намерили n правилни числа
        is_this_number_correct = true;
        int a_copy_of_the_number_we_are_checking = number_for_checking;
        for (int i = 0; i < l; i++) {       //цикъл, който служи за прожерката на всяка липсваща цифра и всяка цифра от сегашното число
            if (number_for_checking % 10 == missing_digits[i] or number_for_checking / 10 == missing_digits[i]or number_for_checking / 100 == missing_digits[i] or number_for_checking / 1000 == missing_digits[i] or number_for_checking / 10000 == missing_digits[i] or number_for_checking / 100000 == missing_digits[i] or number_for_checking / 1000000 == missing_digits[i]) {            //проверка за сяка цифра от сегашното число
                is_this_number_correct = false;
            }
        }
        a_copy_of_the_number_we_are_checking = a_copy_of_the_number_we_are_checking / 10;
        if (is_this_number_correct) {       //проверяваа дали числото може да се направи, и ако може добавя едно към броя на възможните числа
            numbers_so_far_that_are_correct++;
        }
    }
    cout << number_for_checking - 1;    //печати последното без 1 защото цикъла по-горе стига края, прави една стъпка, пак прибав към променливата, но този път не се изпълнява кода защото вече е грешно условието


    return 0;

}
