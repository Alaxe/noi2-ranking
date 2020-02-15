#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAX_N = 2e5 + 10;
string in;
bool gonnaUse[MAX_N];

bool okBruh(int l, int r) {
    if(l == 0 || (in[l - 1] != '*' && in[l - 1] != '/' && in[l - 1] != '-')) {
        if(r == in.size() - 1 || (in[r + 1] != '*' && in[r + 1] != '/')) {
            return true;
        }
    }
}

void fakesubtask() {
    cin >> in;
    int n = in.size();
    for(int i = 0; i < n; i ++) {gonnaUse[i] = true;}
    stack<pair<int, bool> > st;
    for(int i = 0; i < in.size(); i ++) {
        //if(st.empty()) {cout << i << endl;} else {cout << i << " " << st.top().first << " " << st.top().second << endl;}
        if(in[i] == '(') {
            st.push({i, 0});
        } else if(in[i] == ')') {
            bool flag = false;
            if((st.top().first == 0 || in[st.top().first - 1] != '/') && (!st.top().second || okBruh(st.top().first, i))) {
                gonnaUse[st.top().first] = gonnaUse[i] = false;
                flag = st.top().second;
            }
            st.pop();
            if(!st.empty()) {st.top().second |= flag;}
        } else if(in[i] == '+' || in[i] == '-') {
            if(!st.empty()) {st.top().second = true;}
        }
    }
    for(int i = 0; i < n; i ++) {
        if(gonnaUse[i]) {
            cout << in[i];
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    fakesubtask();
    return 0;
}

/*
x+(x+x)
(x+x)+(x+x)
x*(x+x)
(x+x)*x
(x*x)*x+(x*(x+x+x)+(x+x))
*/

/*
((x+x)*x)/x
x+(x*(x-x)-(x-x))
x+((((x/x))))/x
x/((x+x)*x)/x
*/



