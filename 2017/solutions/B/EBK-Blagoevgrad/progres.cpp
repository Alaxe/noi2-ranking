#include <bits/stdc++.h>

using  namespace  std;

struct member {
    int number;
    map <int, int> progreses;
};

unsigned long long allProgreses = 0;

int main() {

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    member allNumbers[n];

    int number;
    cin >> number;
    allNumbers[0].number = number;
    cin >> number;
    allNumbers[1].number = number;
    if (number > allNumbers[0].number) {
        allProgreses++;
        allNumbers[1].progreses[number - allNumbers[0].number] = 1;
    }

    for (int i = 2; i < n; i++) {
        cin >> number;
        allNumbers[i].number = number;
        for (int j = i - 1; j > 0; j--) {
            int currentD = number - allNumbers[j].number;
            if (currentD > 0) {
                allProgreses++;
                allNumbers[i].progreses[currentD] = 1;
                int p = allNumbers[j].progreses[currentD];
                allProgreses += p;
                allNumbers[i].progreses[currentD] += p;
            }
        }
        if (number > allNumbers[0].number) {
            allProgreses++;
            allNumbers[i].progreses[number - allNumbers[0].number] += 1;
        }
    }

    cout << allProgreses << "\n";

    return 0;
}
