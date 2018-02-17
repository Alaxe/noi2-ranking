#include <iostream>
#include <queue>
using namespace std;
const int inf = 100000;
bool g [128][128];
int bezbomba [128][128], sbomba [128][128];
bool used [128][128];
pair <int, int> b, e;
struct str{
    int i;
    int j;
    bool bomb;
    bool operator < (str x) const {
        int p1, p2;
        if (!bomb) p1 = bezbomba [i][j];
        else p1 = sbomba [i][j];
        if (!x.bomb) p2 = bezbomba [x.i][x.j];
        if (x.bomb) p2 = sbomba [x.i][x.j];
        return p1 > p2;
    }
};
int n, m;
bool dijkstra (){
    priority_queue <str> pq;
    str curr;
    str nxt;
    curr.i = b.first;
    curr.j = b.second;
    curr.bomb = 0;
    pq.push (curr);
    bezbomba [b.first][b.second] = 0;
    while (!pq.empty ()){
        curr = pq.top ();
        pq.pop ();
        int i = curr.i, j = curr.j;
        if (i == e.first && j == e.second){
            if (curr.bomb) cout << sbomba [i][j];
            else cout << bezbomba [i][j];
            cout << '\n';
            return 1;
        }
        if (used [i][j]) continue;
        used [i][j] = 1;
        if (i > 0 && !used [i-1][j]){
            int i1 = i - 1, j1 = j;
            if (curr.bomb){
                if (g [i1][j1] == 0 && sbomba [i1][j1] > sbomba [i][j] + 1){
                    sbomba [i1][j1] = sbomba [i][j] + 1;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 1;
                    pq.push (nxt);
                }
            }
            if (!curr.bomb){
                if (g [i1][j1] == 0 && bezbomba [i1][j1] > bezbomba [i][j] + 1){
                    bezbomba [i1][j1] = bezbomba [i][j] + 1;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 0;
                    pq.push (nxt);
                }
                if (g [i1][j1] == 1 && sbomba [i1][j1] > bezbomba [i][j] + 3){
                    sbomba [i1][j1] = bezbomba [i][j] + 3;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 1;
                    pq.push (nxt);
                }
            }
        }
        if (j > 0 && !used [i][j-1]){
            int i1 = i, j1 = j-1;
            if (curr.bomb){
                if (g [i1][j1] == 0 && sbomba [i1][j1] > sbomba [i][j] + 1){
                    sbomba [i1][j1] = sbomba [i][j] + 1;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 1;
                    pq.push (nxt);
                }
            }
            if (!curr.bomb){
                if (g [i1][j1] == 0 && bezbomba [i1][j1] > bezbomba [i][j] + 1){
                    bezbomba [i1][j1] = bezbomba [i][j] + 1;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 0;
                    pq.push (nxt);
                }
                if (g [i1][j1] == 1 && sbomba [i1][j1] > bezbomba [i][j] + 3){
                    sbomba [i1][j1] = bezbomba [i][j] + 3;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 1;
                    pq.push (nxt);
                }
            }
        }
        if (i < n - 1 && !used [i+1][j]){
            int i1 = i + 1, j1 = j;
            if (curr.bomb){
                if (g [i1][j1] == 0 && sbomba [i1][j1] > sbomba [i][j] + 1){
                    sbomba [i1][j1] = sbomba [i][j] + 1;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 1;
                    pq.push (nxt);
                }
            }
            if (!curr.bomb){
                if (g [i1][j1] == 0 && bezbomba [i1][j1] > bezbomba [i][j] + 1){
                    bezbomba [i1][j1] = bezbomba [i][j] + 1;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 0;
                    pq.push (nxt);
                }
                if (g [i1][j1] == 1 && sbomba [i1][j1] > bezbomba [i][j] + 3){
                    sbomba [i1][j1] = bezbomba [i][j] + 3;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 1;
                    pq.push (nxt);
                }
            }
        }
        if (j < m - 1 && !used [i][j+1]){
            int i1 = i, j1 = j+1;
            if (curr.bomb){
                if (g [i1][j1] == 0 && sbomba [i1][j1] > sbomba [i][j] + 1){
                    sbomba [i1][j1] = sbomba [i][j] + 1;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 1;
                    pq.push (nxt);
                }
            }
            if (!curr.bomb){
                if (g [i1][j1] == 0 && bezbomba [i1][j1] > bezbomba [i][j] + 1){
                    bezbomba [i1][j1] = bezbomba [i][j] + 1;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 0;
                    pq.push (nxt);
                }
                if (g [i1][j1] == 1 && sbomba [i1][j1] > bezbomba [i][j] + 3){
                    sbomba [i1][j1] = bezbomba [i][j] + 3;
                    nxt.i = i1;
                    nxt.j = j1;
                    nxt.bomb = 1;
                    pq.push (nxt);
                }
            }
        }
    }
    return 0;
}
int main (){

    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        for (int j = 0;j < m; j ++){
            bezbomba [i][j] = inf;
            sbomba [i][j] = inf;
            char ch;
            cin >> ch;
            if (ch == '#') g [i][j] = 1;
            else g [i][j] = 0;
            if (ch == 'B'){
                b = {i, j};
            }
            if (ch == 'E'){
                e = {i, j};
            }
        }
    }
    bool dali = dijkstra ();
    if (!dali) cout << "-1\n";

    return 0;
}
