#include <iostream>
#include <vector>

using namespace std;

const int kMaxVal = 1e4 + 7;
const int kMaxN = 1e5 + 7;
const int kInf = 1e9 + 7;

struct segment_tree{
    pair<int, int> nodes[4 * kMaxN];
    int lazy[4 * kMaxN];
    int n;

    segment_tree(){}

    pair<int, int> merge(pair<int, int> lvalue, pair<int, int> rvalue){
        if(rvalue.first > lvalue.first)
            return rvalue;
        return lvalue;
    }

    void init(int idx, int l, int r){
        if(l == r){
            nodes[idx] = make_pair(- l - 1, l);
            return;
        }

        int mid = (l + r) >> 1;
        init(2 * idx, l, mid);
        init(2 * idx + 1, mid + 1, r);

        nodes[idx] = merge(nodes[2 * idx], nodes[2 * idx + 1]);
    }

    int resize(int n){
        this->n = n;
        init(1, 0, n - 1);
    }

    void update(int idx, int l, int r, int sl, int sr, int val){
        if(lazy[idx] != 0){
            nodes[idx].first += lazy[idx];
            if(l != r){
                lazy[2 * idx] += lazy[idx];
                lazy[2 * idx + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if(l > sr || r < sl)
            return;
        if(sl <= l && r <= sr){
            nodes[idx].first += val;
            if(l != r){
                lazy[2 * idx] += val;
                lazy[2 * idx + 1] += val;
            }
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * idx, l, mid, sl, sr, val);
        update(2 * idx + 1, mid + 1, r, sl, sr, val);

        nodes[idx] = merge(nodes[2 * idx], nodes[2 * idx + 1]);
    }

    void update(int sl, int sr, int val){
        update(1, 0, n - 1, sl, sr, val);
    }

    pair<int, int> query(int idx, int l, int r, int sl, int sr){
        if(lazy[idx] != 0){
            nodes[idx].first += lazy[idx];
            if(l != r){
                lazy[2 * idx] += lazy[idx];
                lazy[2 * idx + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(l > sr || r < sl)
            return make_pair(-kInf, -1);
        if(sl <= l && r <= sr)
            return nodes[idx];

        int mid = (l + r) >> 1;
        pair<int, int> lvalue = query(2 * idx, l, mid, sl, sr);
        pair<int, int> rvalue = query(2 * idx + 1, mid + 1, r, sl, sr);

        //cout << "query " << idx << " " << l << " " << r << " " << sl << " " << sr << " = " << merge(lvalue,rvalue).first << "," << merge(lvalue,rvalue).second << endl;

        return merge(lvalue, rvalue);
    }

    pair<int, int> query(int sl, int sr){
        return query(1, 0, n - 1, sl, sr);
    }
};

int n;
int a[kMaxN];
segment_tree st;
vector<int> pos[kMaxVal];

int diff(int l, int r, int num){
    int ret = 0;
    for(int i = l; i <= r; ++i)
        ret += abs(a[i] - num);

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n; ++i)
        pos[a[i]].push_back(i);
    st.resize(n);

    int curr_start = 0, ans = 0;
    for(int i = 0; i < kMaxVal; ++i){
        for(int j = 0; j < pos[i].size(); ++j){
            st.update(pos[i][j], n - 1, 2);
        }

        pair<int, int> q = st.query(curr_start, n - 1);
        int to = q.second;
        if(curr_start == 0){
            if(q.first <= 0)
                to = -1;
        }
        else{
            pair<int, int> q2 = st.query(curr_start - 1, curr_start - 1);
            if(q2.first >= q.first)
                to = curr_start - 1;
        }

        ans += diff(curr_start, to, i);
        curr_start = to + 1;
    }

    cout << ans << "\n";
}

