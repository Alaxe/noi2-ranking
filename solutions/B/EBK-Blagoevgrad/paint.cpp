#include <bits/stdc++.h>

using namespace  std;

short area[11000][11000];
int rectangles[1001];
int filledGlobalArea = 0;
bool visited[1001];

int calculatePaintedArea(int clickX, int clickY) {
    int rectangleNumber = area[clickY][clickX];
    if (!visited[rectangleNumber]) {
        visited[rectangleNumber] = true;
        return rectangles[rectangleNumber];
    }

    return 0;
}

int setNewRectangle(int x, int y, int w, int h, int number) {
    w -= 1;
    h -= 1;
    int filledCells = 0;
    short overrideRectangle = 0;

    for (int i = x; i <= x + w; i++) {
        for (int j = y; j <= y + h; j++) {
            if (area[j][i] == 0)
                filledGlobalArea++;

            if (overrideRectangle == 0 && area[j][i] != 0)
                overrideRectangle = area[j][i];

            area[j][i] = number;
            filledCells++;
        }
    }

    rectangles[overrideRectangle] = rectangles[overrideRectangle] - filledCells;

    return filledCells;
}

int main() {

    ios_base::sync_with_stdio(false);

    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    int inputX, inputY, inputW, inputH;

    for (int i = 0; i < n; i++) {
        cin >> inputX >> inputY >> inputW >> inputH;
        rectangles[i + 1] = setNewRectangle(inputX, inputY, inputW, inputH, i + 1);
    }

    int t;
    cin >> t;
    int results[t];

    for (int i = 0; i < t; i++) {
        cin >> inputX >> inputY;
        if (area[inputY][inputX] == 0) {
            if (!visited[0])
                results[i] = (w * h) - filledGlobalArea;
            else
                results[i] = 0;
        } else
            results[i] = calculatePaintedArea(inputX, inputY);
    }

    for (int i = 0; i < t; i++)
        cout << results[i] << "\n";

    return 0;
}
