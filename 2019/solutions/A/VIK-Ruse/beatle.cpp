#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

struct plank{
    int x, y, d;
};

bool cmp(plank lvalue, plank rvalue){
    if(lvalue.y == rvalue.y){
        return lvalue.x < rvalue.x;
    }
    
    return lvalue.y < rvalue.y;
}

plank p[N];

struct segment_tree{
    int node[4*N + 100], lp[4*N + 100];
    
    segment_tree(int n){
        init(0, 0, n - 1);
    }
    
    bool improve(int &curr_val, int new_val){
        if(curr_val == -1){
            curr_val = new_val;
            
            return true;
        }
        if(new_val == -1){
            return false;
        }
        
        if(p[curr_val].y < p[new_val].y){
            curr_val = new_val;
            
            return true;
        }
        
        return false;
    }
    
    void init(int ind, int l, int r){
        node[ind] = -1;
        lp[ind] = -1;
        
        if(l == r){
            return ;
        }
        
        int mid = (l + r) / 2;
        
        init(2*ind + 1, l, mid);
        init(2*ind + 2, mid+1, r);
        
        return ;
    }
    
    void update(int ind, int l, int r, int sl, int sr, int val){
        if(lp[ind] != -1){
            improve(node[ind], lp[ind]);
            
            if(l != r){
                improve(lp[2*ind + 1], lp[ind]);
                improve(lp[2*ind + 2], lp[ind]);
            }
            lp[ind] = -1;
        }
        if(sl <= l && r <= sr){
            improve(lp[ind], val);
            
            return ;
        }
        if(l > sr || r < sl){
            return ;
        }
        
        int mid = (l + r) / 2;
        
        update(2*ind + 1, l, mid, sl, sr, val);
        update(2*ind + 2, mid+1, r, sl, sr, val);
        
        node[ind] = node[2*ind + 1];
        improve(node[ind], node[2*ind + 2]);
    }
    
    int query(int ind, int l, int r, int sl, int sr){
        if(lp[ind] != -1){
            improve(node[ind], lp[ind]);
            
            if(l != r){
                improve(lp[2*ind + 1], lp[ind]);;
                improve(lp[2*ind + 2], lp[ind]);
            }
            lp[ind] = -1;
        }
        if(sl <= l && r <= sr){
            return node[ind];
        }
        if(l > sr || r < sl){
            return -1;
        }
        int mid = (l + r) / 2;
        int ret = query(2*ind + 1, l, mid, sl, sr);
        
        improve(ret, query(2*ind + 2, mid+1, r, sl, sr));
        
        return ret;
    }
};

int fall[N], fall_p[N][2];
segment_tree tree(N);

int dp[N];
vector<int> res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y >> p[i].d;
    }
    
    sort(p, p+n, cmp);
    
    for(int i = 0; i < n; i++){
        fall_p[i][0] = tree.query(0, 0, N - 1, p[i].x - 1, p[i].x - 1);
        fall_p[i][1] = tree.query(0, 0, N - 1, p[i].x + p[i].d, p[i].x + p[i].d);
        
        tree.update(0, 0, N - 1, p[i].x, p[i].x + p[i].d - 1, i);
    }
    
    for(int i = 0; i < N; i++){
        fall[i] = tree.query(0, 0, N - 1, i, i);
    }
    
    for(int i = 0; i < n; i++){
        if(fall_p[i][0] == -1 || fall_p[i][1] == -1){
            dp[i] = 1;
            
            continue;
        }
        
        dp[i] = 1 + min(dp[ fall_p[i][0] ], dp[ fall_p[i][1] ]);
    }
    
    int q;
    
    cin >> q;
    
    while(q--){
        int x;
        
        cin >> x;
        
        if(fall[x] == -1){
            res.push_back(0);
        }
        else{
            res.push_back(dp[fall[x]]);
        }
    }
    
    for(int i = 0; i < (int)res.size() - 1; i++){
        cout << res[i] << " ";
    }
    cout << res.back() << "\n";
    
    return 0;
}
/*
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/