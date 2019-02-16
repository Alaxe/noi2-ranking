#include <bits/stdc++.h>
#define MAXN 100003

using namespace std;

int n, t, points;

struct duska {
    int x, y, d;
    int val;
}a[MAXN];

queue <int> ans;
vector <duska> rows[MAXN];

bool cmp(const duska A, const duska B) {
    if (A.y == B.y) return A.x < B.x;
    return A.y < B.y;
}

int Left(int X, int Y, int D, int pos) {
    for (int i = pos-1; i > 0; i--) {
        if (X <= rows[i][0].x) continue;
        for (int j = 0; j < rows[i].size(); j++) {
            if (X > rows[i][j].x && X <= rows[i][j].x+rows[i][j].d) return rows[i][j].val;
            if (X <= rows[i][j].x) break;
        }
    }
    return 0;
}

int Right(int X, int Y, int D, int pos) {
    for (int i = pos-1; i > 0; i--) {
        int SIZE = rows[i].size();
        if (X+D >= rows[i][SIZE-1].x+rows[i][SIZE-1].d) continue;
        for (int j = SIZE-1; j >= 0; j--) {
            if (X+D >= rows[i][j].x && X+D < rows[i][j].x+rows[i][j].d) return rows[i][j].val;
            if (X+D >= rows[i][j].x+rows[i][j].d) break;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].d);

    sort(a, a+n, cmp);

    int ind = 1;

    for (int i = 0; i < n; i++) {
        rows[ind].push_back(a[i]);
        if (a[i].y < a[i+1].y) ind++;
    }

    for (int i = 0; i < rows[1].size(); i++)
        rows[1][i].val = 1;

    for (int i = 2; i <= ind; i++) {
        for (int j = 0; j < rows[i].size(); j++) {
            rows[i][j].val = 1;
            rows[i][j].val += min(Left(rows[i][j].x, rows[i][j].y, rows[i][j].d, i),
                                  Right(rows[i][j].x, rows[i][j].y, rows[i][j].d, i));
        }
    }

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &points);
        bool flag = false;
        for (int j = ind; j >= 1; j--) {
            if (points < rows[j][0].x || points >= rows[j][rows[j].size()-1].x+rows[j][rows[j].size()-1].d) continue;
            for (int k = 0; k < rows[j].size(); k++)
                if (rows[j][k].x <= points && rows[j][k].x+rows[j][k].d > points) {
                    ans.push(rows[j][k].val);
                    flag = true; break;
                }
            if (flag) break;
        }
        if (!flag) ans.push(0);
    }

    while (ans.size() > 1) {
        printf("%d ", ans.front());
        ans.pop();
    }
    printf("%d\n", ans.front());
    ans.pop();
    return 0;
}
