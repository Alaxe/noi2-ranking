#include <bits/stdc++.h>
using namespace std;

int main () {

int n, a, b, m, mini, maxi, p, answer, answer1;
cin >> n;
mini = 0;
maxi = n-1;
int x[n], ans[n];

for (int i=0; i < n; i++) {
    cin >> x[i];
}

cin >> m;
sort (x, x + n);

for (int j=0; j < m; j++) {
    cin >> a >> b;
    mini = 0;
    maxi = n-1;
    p = 3;
    if (x[0] >= a) {answer = 0;}
    else if (x[n-1] < a) {answer = n;}
    else {
    while (p >= 0) {
    p = (mini+maxi)/2;
    if (x[p] >= a) {
        maxi = p;
    }
    else {
        mini = p;
    }
    if (maxi - mini <= 3) {
        for (int i=mini; i <= maxi; i++) {
            if (x[i] < a and x[i+1] >= a) {answer = i+1; p=-1;}
        }
    }
}
    }
    mini = 0;
    maxi = n-1;
    p = 3;
    if (x[n-1] <= b) {answer1=0;}
    else if (x[0] > b) {answer1=n;}
    else {
        while (p >= 0) {
    p = (mini+maxi)/2;
    if (x[p] > b) {
        maxi = p;
    }
    else {
        mini = p;
    }
    if (maxi - mini <= 3) {
        for (int i=mini; i <= maxi; i++) {
            if (x[i] <= b and x[i+1] > a) {answer1 = n-i-1; p=-1;}
        }
    }
}
    }
    cout << n - answer - answer1 << endl;
}

return 0;
}
