#include <bits/stdc++.h>

using namespace  std;

long w, h, inputX1, inputY1, inputX2, inputY2;
unsigned long long total;

void validateCoordinatesInput() {
    if (inputY1 > inputY2)
        swap(inputY1, inputY2);
}

int main() {

    ios_base::sync_with_stdio(false);

    cin >> w >> h;
    total = w * h;
    int n;
    cin >> n;

    int line[h];
    fill(line, line + h, 0);

    for (int i = 0; i < n / 2; i++) {
        cin >> inputX1 >> inputY1 >> inputX2 >> inputY2;
        validateCoordinatesInput();
        for (long j = inputY1; j < inputY2; j++) {
            if (inputX1 > line[j]) {
                if (line[j] == 0)
                    total -= inputX1;
                else
                    total -= inputX1 - line[j];

                line[j] = inputX1;
            }
        }
    }

    cout << total << "\n";

    return 0;
}
