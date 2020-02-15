#include <bits/stdc++.h>

#pragma GCC optimize "-O3"

#define endl '\n'
#define trace(x) cerr << #x << " = " << x << endl

using namespace std;

class Interval {
public:

    int from;
    int to;
    bool haveOnlyMultiply;

    Interval(int from, int to, int haveOnlyMultiply) {
        this->from = from;
        this->to = to;
        this->haveOnlyMultiply = haveOnlyMultiply;
    }
};

class Entity {
public:

    int from;
    bool haveOnlyMultiply;

    Entity(int from) {
        this->from = from;
        this->haveOnlyMultiply = true;
    }
};

int getPriority(char ch) {
    if (ch == '+') {
        return 1;
    }

    if (ch == '*') {
        return 2;
    }

    return (int)1e9;
}

string ex;
int n;
vector<Interval> intervals;

bool canReduce(int index) {
    if (intervals[index].haveOnlyMultiply) {
        return true;
    }

    int from = intervals[index].from;
    int to = intervals[index].to;

    if (from > 0 && ((ex[from - 1] == '*') || (ex[from - 1] == '/') || (ex[from - 1] == '-'))) {
        return false;
    }

    if (to < (n - 1) && ((ex[to + 1] == '*') || (ex[to + 1] == '/'))) {
        return false;
    }

    if (!intervals[index].haveOnlyMultiply) {
        if (from > 0 && to < (n - 1)) {
            if (ex[from - 1] == '(' && ex[to + 1] == ')') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> ex;

    n = (int)ex.size();

    stack<Entity> activeIntervals;
    vector<int> indexes(n, -1);

    for (int i = 0; i < n; i++) {
        if (ex[i] == '(') {
            activeIntervals.emplace(i);
        } else if (ex[i] == ')') {
            int from = activeIntervals.top().from;
            intervals.emplace_back(from, i, activeIntervals.top().haveOnlyMultiply);
            indexes[from] = indexes[i] = (int)intervals.size() - 1;
            activeIntervals.pop();
        } else if (ex[i] == '+' || ex[i] == '-') {
            if (!activeIntervals.empty()) {
                activeIntervals.top().haveOnlyMultiply = false;
            }
        }
    }

    /*
    cout << "Bracket intervals: \n";
    for (auto &i : intervals) {
        cout << i.from << ' ' << i.to << ' ' << i.haveOnlyMultiply << endl;
    }
    */

    string answer;
    for (int i = 0; i < n; i++) {
        if (ex[i] == '(' || ex[i] == ')') {
            if (canReduce(indexes[i])) {
                continue;
            } else {
                answer.push_back(ex[i]);
            }
        } else {
            answer.push_back(ex[i]);
        }
    }

    cout << answer << endl;

    return EXIT_SUCCESS;
}
