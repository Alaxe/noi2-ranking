#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, W1, W2, number, a = 0, b = 0, maxA = 0, maxB = 0;

vector<int> numbers;

vector<int> numsToDelete, finalNumbersToDelete;

void removeElement(int el) {

    for (int i=0;i<n;++i) {

        if (numbers[i] == el) {

            numbers[i] = 0;

            break;

        }

    }

}

int main() {

    cin >> n >> W1 >> W2;

    if (W1 > W2) {

        int temp = W1;
        W1 = W2;
        W2 = temp;

    }

    for (int i=0;i<n;++i) {

        cin >> number;

        numbers.push_back(number);

    }

    sort(numbers.begin(), numbers.end());

    vector<int>::iterator j;

    do {

        for (int i=0;i<n;++i) {

            if (W1 == a) {

                maxA = a;

                break;

            }

            if (W1 - a >= numbers[i]) {

                a += numbers[i];

                numsToDelete.push_back(numbers[i]);

            }

        }

        if (maxA <= a) {

            maxA = a;

            finalNumbersToDelete.clear();

            for (j = numsToDelete.begin(); j != numsToDelete.end(); ++j)
                    finalNumbersToDelete.push_back(*j);

        }

        a = 0;

        numsToDelete.clear();

        if (maxA == W1)
            break;

    } while(next_permutation(numbers.begin(), numbers.end()));

    vector<int>::iterator i;

    for (i = finalNumbersToDelete.begin(); i != finalNumbersToDelete.end(); ++i) {

        removeElement(*i);

    }

    do {

        for (int i=0;i<n;++i) {

            if (W2 - b == 0) {

                maxB = b;

                break;

            }

            if (W2 - b >= numbers[i]) {

                b += numbers[i];

            }

        }

        if (maxB < b) {

            maxB = b;

        }

        b = 0;

        if (maxB == W2)
            break;

    } while(next_permutation(numbers.begin(), numbers.end()));

    cout << maxA + maxB;

    return 0;

}
