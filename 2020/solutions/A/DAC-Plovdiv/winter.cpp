#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAXN 10001
#define MAXM 100001

vector<int> vec[MAXN];
vector<int> connect;
int x[MAXM] = {}, y[MAXM] = {}, n, m;
int ans[MAXN][MAXN] = {};
bool used[MAXN] = {};

bool bfs (int u, int v) {
    bool flag = false;

    int uor = u;
    queue<int> q;
    q.push(u);
    used[u] = true;

    while(!q.empty()) {
        u = q.front();
        q.pop();
        connect.push_back(u);

        for(int i = 0; i < vec[u].size(); i++) {
            int w = vec[u][i];
            if(w == v && u != uor) {
                flag = true;
            }

            if((u == uor && w != v) || (u != uor)) {
                if(used[w] == false) {
                    q.push(w);
                    used[w] = true;
                }
            }
        }
    }

    return flag;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(int i = 0; i < m; i++) {
        cin>>x[i]>>y[i];
        vec[x[i]].push_back(y[i]);
        vec[y[i]].push_back(x[i]);
    }

    for(int i = 0; i < m; i++) {
        memset(used, 0, sizeof(used));
        connect.clear();

        bool flag = bfs(x[i], y[i]);
        //<<flag<<endl;

        for(int j = 0; j < connect.size(); j++) {
            for(int l = j+1; l < connect.size(); l++) {
                ans[connect[j]][connect[l]]++;
                ans[connect[l]][connect[j]]++;
                //cout<<connect[j]<<connect[l]<<ans[connect[j]][connect[l]]<<endl;
            }
        }

        if(flag == false) {
            memset(used, 0, sizeof(used));
            connect.clear();

            bfs(y[i], x[i]);

            for(int j = 0; j < connect.size(); j++) {
                for(int l = j+1; l < connect.size(); l++) {
                    ans[connect[j]][connect[l]]++;
                    ans[connect[l]][connect[j]]++;
                    //cout<<connect[j]<<connect[l]<<ans[connect[j]][connect[l]]<<endl;
                }
            }
        }
    }

    int br = 0;

    for(int j = 1; j <= n; j++) {
        for(int l = j+1; l <= n; l++) {
            if(ans[j][l] == m) br++;
            //cout<<l<<j<<ans[j][l]<<endl;}
        }
    }

    cout<<br<<endl;
    return 0;
}
/*
5 5
1 2
2 3
3 1
2 4
2 5
*/
