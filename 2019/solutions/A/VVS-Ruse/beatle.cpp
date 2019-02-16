#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define endl '\n'

using namespace std;

const int N = (int)(1e5) + 3, INF = (int)(1e9);

int n;

struct Line {
    int y, lx, rx, idx;
} a[N];
bool done[N];
int ans[N];

char ch;
void read(int &aa) {
    aa = 0;
    ch = getchar();
    while(ch > 47 && ch < 58) {
        aa = (aa << 1) + (aa << 3) + ch - 48;
        ch = getchar();
    }
}

bool cmp(Line aa, Line bb) {
    return aa.rx < bb.rx;
}

int query(int qy, int qx) {
    int Left = 0, Right = n - 1;
    int Mid;
    while(Left <= Right) {
        Mid = (Left + Right) >> 1;
        if(qx + 1 <= a[Mid].rx) {
            Right = Mid - 1;
        } else Left = Mid + 1;
    }
    int saveidx = -1, maxy = -1;
    for(int i = Left; i < n; ++i) {
        if(a[i].lx <= qx && a[i].y < qy) {
            if(maxy < a[i].y) {
                maxy = a[i].y;
                saveidx = i;
            }
        }
    }
    //cout << "for " << qx << ", " << qy << " i found " << a[saveidx].lx << " " << a[saveidx].rx << " " << endl;
    return saveidx;
}

int solve(int Idx) {
    if(done[Idx]) {
        return ans[Idx];
    }
    done[Idx] = 1;
    int a1 = 1, a2 = 1;
    //left
    int ql = query(a[Idx].y, a[Idx].lx - 1);
    if(ql != -1) {
        a1 += solve(ql);
    }
    //right
    int qr = query(a[Idx].y, a[Idx].rx);
    if(qr != -1) {
        a2 += solve(qr);
    }
    return ans[Idx] = min(a1, a2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    read(n);
    int starty = -1;
    int x, y, z;
    for(int i = 0; i < n; ++i) {
        read(x); read(y); read(z);
        starty = max(starty, y);
        a[i].y = y;
        a[i].lx = x;
        a[i].rx = x + z;
        a[i].idx = i;
    }
    starty++;
    
    sort(a, a + n, cmp);
    for(int i = 0; i < n; ++i) {
        if(!done[i]) {
            ans[i] = solve(i);
        }
    }
    
    vector<int> res;
    int t;
    int spos;
    int idxx;
    read(t);
    while(t--) {
        read(spos);
        idxx = query(starty, spos);
        if(idxx == -1) res.push_back(0);
        else res.push_back(solve(idxx));
    }
    cout << res[0];
    for(int i = 1; i < (int)res.size(); ++i) {
        cout << ' ' << res[i];
    }
    cout << endl;

    return 0;
}