#include <bits/stdc++.h>

using namespace std;

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
}

struct point {
    int x, y, index;
};

string numToStr(int a) {
    string s = "";

    while (a != 0) {
        s += char('0' + a % 10);
        a = a / 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string pointId(int a, int b, int c) {
    string id = numToStr(a) + numToStr(b) + numToStr(c);
    sort(id.begin(), id.end());

    return id;
}

bool exists(string a, char b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] == b)
            return true;

    return false;
}

void add(string &a, string b) {
    for (int i = 0; i < b.size(); i++) {
        if (!exists(a, b[i])) {
            // cout << "\t" << b[i] << " doesnt exist in " << a<< "\n";
            a += b[i];
        }
    }

    sort(a.begin(), a.end());
}

int main() {

    int n, x, y;
    cin >> n;
    vector<point> points;
    vector<vector<int>> usedPoints;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        point p;
        p.x = x;
        p.y = y;
        p.index = i + 1;
        points.push_back(p);
    }

    int MAX = 0;
    vector<int> maxId;

    for (int i = 0; i < n; i++) {
        int currentMax = 0;
        vector<int> currentMaxId;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                /*vector<int> currentId;
                // string currentId = pointId(points[i].index, points[j].index, points[k].index);
                if (find(currentId.begin(), currentId.end(), points[i].index) == currentId.end()) {
                    currentId.push_back(points[i].index);
                }
                if (find(currentId.begin(), currentId.end(), points[j].index) == currentId.end()) {
                    currentId.push_back(points[j].index);
                }
                if (find(currentId.begin(), currentId.end(), points[k].index) == currentId.end()) {
                    currentId.push_back(points[k].index);
                }*/

                if (points[i].index != points[j].index && points[j].index != points[k].index && points[i].index != points[k].index){
                    // && !exists(currentMaxId, numToStr(points[i].index)) && !exists(currentMaxId, numToStr(points[j].index)) && !exists(currentMaxId, numToStr(points[k].index))) {
                    currentMax += collinear(points[i].x, points[i].y, points[j].x, points[j].y, points[k].x, points[k].y);
                   /*usedPoints.push_back(currentId);

                    if (find(currentMaxId.begin(), currentMaxId.end(), points[i].index) == currentMaxId.end()) {
                        currentMaxId.push_back(points[i].index);
                    }
                    if (find(currentMaxId.begin(), currentMaxId.end(), points[j].index) == currentMaxId.end()) {
                        currentMaxId.push_back(points[j].index);
                    }
                    if (find(currentMaxId.begin(), currentMaxId.end(), points[k].index) == currentMaxId.end()) {
                        currentMaxId.push_back(points[k].index);
                    }*/
                    /*cout << currentId << "\n";

                    if (currentMaxId == "") {
                        currentMaxId = currentId;
                    } else {
                        add(currentMaxId, currentId);
                    }*/

                    /*if (collinear(points[i].x, points[i].y, points[j].x, points[j].y, points[k].x, points[k].y)) {
                        cout << points[i].index << " " << points[j].index << " " << points[k].index << "\n\n";
                    }*/
                }
            }
        }

        if (MAX < currentMax) {
            MAX = currentMax;
        }
    }

    cout << MAX/2 << "\n";

    return 0;
}
