#include <iostream>
using namespace std;

int abs(int n) {
    if (n < 0)
        return -n;
    return n;
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    unsigned int n;
    cin >> n;
    n--;
    int a[n];
    int last;
    cin >> last;
    for (int i=0; i<n; i++) {
        int newest;
        cin >> newest;
        a[i] = newest-last; // store the deltas of the numbers instead of the numbers themselves
        last = newest;
    }
    unsigned int increments = 0;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i=0; i<n; i++) {
            if (a[i] < 0) {
                sorted = false;
                int d = 1;
                while (true) {
                    if (i+d==n) {
                        increments -= d*a[i];
                        a[i] = 0;
                        break;
                    }
                    if (i-d < 0) {
                        increments -= d*a[i];
                        a[i] = 0;
                        break;
                    }
                    if (a[i-d]>0) {
                        int subtractable = min(a[i-d], -a[i]);
                        increments += d*subtractable;
                        a[i-d] -= subtractable;
                        a[i] += subtractable;
                        if (a[i]>=0) {
                            break;
                        }
                    }
                    if (a[i+d]>0) {
                        int subtractable = min(a[i+d], -a[i]);
                        increments += d*subtractable;
                        a[i+d] -= subtractable;
                        a[i] += subtractable;
                        if (a[i]>=0) {
                            break;
                        }
                    }
                    d++;
                }
            }
        }
    }
    cout << increments << endl;
}
