#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX_N = 11005;

struct Rectangle {
    int x, y, w, h, area;

    Rectangle(){}
    Rectangle(int x, int y, int w, int h) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        area = w * h;
    }

    bool is_in(Rectangle other) {
        int x1 = x + w, y1 = y + h;

        if(x < other.x && y < other.y && x1 > other.x && y1 > other.y) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator< (const Rectangle &other) const {
        return area < other.area;
    }
};

int areas[MAX_N];
Rectangle rs[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h;
    cin>>w>>h;
    rs[0] = Rectangle(0, 0, w, h);

    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        int x, y, w, h;
        cin>>x>>y>>w>>h;
        rs[i] = Rectangle(x, y, w, h);
    }

    sort(rs, rs + n + 1);

    for(int i = 0; i <= n; i++) {
        areas[i] = rs[i].area;
    }
    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(rs[j].is_in(rs[i])) {
                areas[j] -= areas[i];
            }
        }
    }

    int t;
    cin>>t;
    for(int i = 0; i < t; i++) {
        int x, y;
        cin>>x>>y;

        int curr_ans;
        for(int j = 0; j <= n; j++) {
            if(rs[j].is_in(Rectangle(x, y, 0, 0))) {
                curr_ans = areas[j];
                break;
            }
        }

        cout<<curr_ans<<endl;
    }

    return 0;
}

/**
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3
*/
