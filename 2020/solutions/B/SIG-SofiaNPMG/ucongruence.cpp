#include<iostream>

using namespace std;

int N, U, maxValue = 0, c = 1, n = 0, br = 1;
int numbers[1000000];

void calculateMinN() {

    int k = U - c + 2;

    for (int i=1;i<=k;++i) {

        n += (c - 2) * (k - i + 1);

    }

}

int getMin(int a) {

    int m = 10000;

    for (int i=0;i<N;++i) {

        if (numbers[i] >= a) {

            if (m > numbers[i]) {

                m = numbers[i];

            }

        }

    }

    return m;

}

int getMax(int a) {

    int m = 0;

    for (int i=0;i<N;++i) {

        if (numbers[i] < a) {

            if (m < numbers[i]) {

                m = numbers[i];

            }

        }

    }

    return m;

}

void findAndReplace(int a, int b) {

    for (int i=0;i<N;++i) {

        if (numbers[i] == a) {

            numbers[i] = b;

        }

    }

}

int main() {

    cin >> N >> U;

    for (int i=0;i<N;++i) {

        cin >> numbers[i];

        if (maxValue < numbers[i]) {

            maxValue = numbers[i];

        }

    }

    int changer = getMin(0);

    while (changer != 10000) {

        findAndReplace(changer, c);

        changer = getMin(c+1);

        c++;

    }

    calculateMinN();

    while (br != (n+1)/2) {

        int m = c - 1, o = getMin(0);

        while (getMin(0) != U - (c-1-o)) {

            for (int i=m;i<=U;++i) {

                br++;

                if (br == (n+1)/2)
                    break;

            }

            if (br == (n+1)/2)
                break;

            for (int i=0;i<N;++i) {

                if (numbers[i] == m) {

                    numbers[i]++;

                }

            }

            for (int i=0;i<N;++i) {

                if (numbers[i] == getMax(m)) {

                    numbers[i]++;

                }

            }

            m += 1;

        }

    }

    for (int i=0;i<N;++i) {

        cout << numbers[i] << " ";

    }

    return 0;

}
