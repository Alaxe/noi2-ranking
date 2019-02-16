#include<bits/stdc++.h>
using namespace std;

const int MAX_X = 200001;

pair<pair<int, int>, int> boards[100000];
int tree[1000000];
int lazy[1000000];

int value(int index, int left, int right, int queryIndex) {
    if (lazy[index] != 0) return lazy[index];

    if (left == right) return tree[index];
    int middle = (left+right)/2;
    if (queryIndex <= middle) return value(2*index,left,middle,queryIndex);
    else return value(2*index+1,middle+1,right,queryIndex);
}

void update(int index, int left, int right, int x, int y, int v) {
    if (right < x || y < left) return;
    else if (x <= left && right <= y) tree[index]=lazy[index]=v;
    else {
        if (lazy[index] != 0) {
            lazy[2*index]=lazy[index];
            lazy[2*index+1]=lazy[index];
            lazy[index]=0;
        }
        int middle = (left+right)/2;
        update(2*index, left, middle, x, y, v);
        update(2*index+1, middle+1, right, x, y, v);
        tree[index] = min(tree[2*index], tree[2*index+1]);
    }
}

void precompute(int N) {
    for (int i = 0; i < N; i++) {
        auto p = boards[i];
        int x1 = p.first.second;
        int x2 = x1 + p.second;
        int ans = min(value(1,1,MAX_X,x1), value(1,1,MAX_X,x2+1))+1;
        update(1,1,MAX_X,x1+1,x2,ans);
    }
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, d; cin >> x >> y >> d;
        boards[i] = {{y, x}, d};
    }
    sort(boards, boards+N);
    precompute(N);

    int T; cin >> T;
    while (T--) {
        int X; cin >> X;
        cout << value(1,1,MAX_X,X+1) << " ";
    }
    cout << endl;

    return 0;
}
