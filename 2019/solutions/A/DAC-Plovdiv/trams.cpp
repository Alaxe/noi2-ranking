#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <iostream>
using namespace std;

#define MAXN 50100
vector<int> route;

vector<int> vec[MAXN];

map<pair<int, int>, bool> used;
int D[MAXN]={};

void dfs(int u){
    for(int i = 0; i < vec[u].size(); i++){
        int v = vec[u][i];
        if(used[make_pair(min(u, v), max(u, v))] == false){
            used[make_pair(min(u, v), max(u, v))] = true;
            D[u]--;
            D[v]--;

            dfs(v);
            route.push_back(u);
            return;
        }
    }
}

int main(){
    int n, m, x, y;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);

        used[make_pair(min(x, y), max(x, y))] = false;
        D[x]++;
        D[y]++;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    vector<vector<int> > answer;
    for(int i = 1; i <= n; i++){
        route.clear();
        if(D[i] % 2 == 1) dfs(i);
        if(route.size() >= 2)
            answer.push_back(route);
    }

    for(int i = 1; i <= n; i++){
        route.clear();
        dfs(i);
        if(route.size() >= 2)
            answer.push_back(route);

    }

    cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++){
        printf("%d ", answer[i].size());
        for(int j = 0; j < answer[i].size(); j++){
            if(j == answer[i].size() - 1) printf("%d\n", answer[i][j]);
            else printf("%d ", answer[i][j]);
        }
    }
    return 0;
}
/*
8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3
*/
