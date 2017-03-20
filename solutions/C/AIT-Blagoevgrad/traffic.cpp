#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
char ch [640][640];
bool visitted [640][640];
int pyt [640][640];
struct str{
    int x;
    int y;
    int pyt;
    bool operator < (str a) const{
        return pyt < a.pyt;
    }
};
priority_queue <str> pq;
void dijkstra (){
    while (!pq.empty ()){
        str a = pq.top ();
        pq.pop ();
        int i = a.x, j = a.y, p = a.pyt;
        if (visitted [i][j]) continue;
        str b;
        b.pyt = p + ch [i][j] - 'A' + 1;
        if (ch [i][j] == '#') b.pyt = 0;
        visitted [i][j] = 1;
        pyt [i][j] = p;
        if (i > 0 && !visitted [i - 1][j]){
            b.x = i - 1;
            b.y = j;
            pq.push (b);
        }
        if (i < n && !visitted [i + 1][j]){
            b.x = i + 1;
            b.y = j;
            pq.push (b);
        }
        if (j > 0 && !visitted [i][j - 1]){
            b.x = i;
            b.y = j - 1;
            pq.push (b);
        }
        if (j < m && !visitted [i][j + 1]){
            b.x = i;
            b.y = j + 1;
            pq.push (b);
        }
    }
}
int main(){

	ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cin >> ch [i][j];
            if (ch [i][j] == '#'){
                x = i; y = j;
            }
            if (ch [i][j] == '*'){
                visitted [i][j] = 1;
            }
        }
    }
    n --; m --;
    if (x == 0 || x == n || y == 0 || y == m){
        cout << "0\n";
        return 0;
    }
    str a;
    a.x = x; a.y = y; a.pyt = 0;
    pq.push (a);
    dijkstra ();
    int mini = 20000000;
    for (int i = 0; i <= n; i ++){
        if (ch [i][0] >= 'A' && ch [i][0] <= 'Z' && visitted [i][0]) mini = min (pyt [i][0] + ch [i][0] - 'A' + 1, mini);
        if (ch [i][m] >= 'A' && ch [i][m] <= 'Z' && visitted [i][m]) mini = min (pyt [i][m] + ch [i][m] - 'A' + 1, mini);
    }
    for (int j = 1; j < m; j ++){
        if (ch [0][j] >= 'A' && ch [0][j] <= 'Z' && visitted [0][j]) mini = min (pyt [0][j] + ch [0][j] - 'A' + 1, mini);
        if (ch [n][j] >= 'A' && ch [n][j] <= 'Z' && visitted [n][j]) mini = min (pyt [n][j] + ch [n][j] - 'A' + 1, mini);
    }
    cout << mini << '\n';

	return 0;
}
/*
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
*/
