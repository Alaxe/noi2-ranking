#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define Int unsigned long long
#define mp make_pair
using namespace std;

const int MAX_N = 1e5 + 5;

struct Event {
    Int row, col, row_e;
    char type;

    Event(){}
    Event(Int row, Int col, char type, Int row_e) {
        this->row = row;
        this->col = col;
        this->type = type;
        this->row_e = row_e;
    }

    bool operator< (const Event &other) const {
        if(row != other.row) {
            return row < other.row;
        }
        else {
            return type > other.type;
        }
    }
};
struct Pair {
    Int first, second;

    Pair(){}
    Pair(Int first, Int second) {
        this->first = first;
        this->second = second;
    }

    bool operator< (const Pair &other) const {
        return second < other.second;
    }
};

Int x[MAX_N], y[MAX_N];
Event e[2 * MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Int w, h;
    cin>>w>>h;

    int n, ind = 0;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>x[i]>>y[i];

        if(i != 0) {
            if(x[i - 1] == x[i] && y[i - 1] < y[i]) {
                e[ind] = Event(y[i - 1], x[i - 1], 'b', y[i]);
                ind++;
                e[ind] = Event(y[i], x[i], 'e', 0);
                ind++;
            }
            else if(x[i - 1] == x[i] && y[i - 1] > y[i]) {
                e[ind] = Event(y[i], x[i], 'b', y[i - 1]);
                ind++;
                e[ind] = Event(y[i - 1], x[i - 1], 'e', 0);
                ind++;

            }
        }
    }

    sort(e, e + ind);

    priority_queue<Pair> pq;
    Int ans = 0;
    for(int i = 0; i < ind - 1; i++) {
        while(e[i].row == e[i + 1].row) {
            if(e[i].type == 'b') {
                pq.push(Pair(e[i].row_e, e[i].col));
            }
            i++;

            if(i == ind - 1) {
                break;
            }
        }
        if(e[i].type == 'b') {
            pq.push(Pair(e[i].row_e, e[i].col));
        }

        if(i == ind - 1) {
            break;
        }

        while(!pq.empty()) {
            if(e[i].row < pq.top().first) {
                break;
            }
            pq.pop();
        }

        ans += (e[i + 1].row - e[i].row) * pq.top().second;
    }

    cout<<h * w - ans<<endl;
    return 0;
}

/**
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
