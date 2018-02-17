#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX_N = 1005;
const double EPS = 0.0000001;

class Point {
public:
    int x, y;

    pair< double, double > GetLinearEquation(const Point &other) {
        double a, b;

        a = ((double) y - (double) other.y) / ((double) x - (double) other.x);
        b = y - a * x;

        return { a, b };
    }
};

int n, ans;
Point points[MAX_N];
vector< pair< double, double > > linearEquations;
unordered_map< int, int > cntOnX;

void CheckVertical() {
    for(int i = 0; i < n; i++) {
        cntOnX[points[i].x]++;
        ans = max(ans, cntOnX[points[i].x]);
    }
}

void CheckOther() {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(points[i].x == points[j].x) {
                continue;
            }

            linearEquations.push_back(points[i].GetLinearEquation(points[j]));
        }
    }

    sort(linearEquations.begin(), linearEquations.end());

    int currCnt = 1, maxCnt = 1;
    for(int i = 1; i < linearEquations.size(); i++) {
        if(fabs(linearEquations[i - 1].first - linearEquations[i].first) <= EPS && fabs(linearEquations[i - 1].second - linearEquations[i].second) <= EPS) {
            currCnt++;
        }

        if(!(fabs(linearEquations[i - 1].first - linearEquations[i].first) <= EPS && fabs(linearEquations[i - 1].second - linearEquations[i].second) <= EPS) || i == linearEquations.size() - 1) {
            if(maxCnt < currCnt) {
                maxCnt = currCnt;
            }
            currCnt = 1;
        }
    }

    ans = max(ans, (int) sqrt(2 * maxCnt) + 1);
}

int main() {
    cout << fixed << setprecision(20);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    CheckVertical();
    CheckOther();

    cout << ans << endl;
    return 0;
}
