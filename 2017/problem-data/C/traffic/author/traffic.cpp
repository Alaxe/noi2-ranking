#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
//#include <ctime>
#define MAX_DIM 1200

using namespace std;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

struct cell {
  int row, col, d;
  bool operator < (const cell &toll) const { return d > toll.d;}
};

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int> > dist(n, vector<int>(m));  // rows X cols
    vector<vector<bool> > inspected(n, vector<bool>(m));
    priority_queue<cell> pq;
    char c;
    cell start;
    //clock_t begin = clock();
    for(int i = 0; i<n; i++) {
        for(int j = 0; j < m; j++) {
                cin >> c;
           switch(c)
                 {
                  case '#':
                           start.row = i;
                           start.col = j;
                           start.d = 0;
                           break;
                  case '*':
                           dist[i][j] = -1;
                           break;
                  default:
                          dist[i][j] = c - 'A' + 1;
                          break;
                }
          }
    }
    pq.push(start);
    while(!pq.empty()) {
      cell cur = pq.top();
      pq.pop();
      if(inspected[cur.row][cur.col]) continue;
      //cout << "Cur--> " << cur.row << " "<<cur.col <<" "<< cur.d << endl;
      inspected[cur.row][cur.col] = true;
      if(cur.row == 0 || cur.row == n - 1 || cur.col == 0 || cur.col == m - 1) {
         cout << cur.d << endl;
         break;
      }
      for (int i = 0; i < 4; i++) {
        cell next;
        next.row = cur.row + dr[i];
        next.col = cur.col + dc[i];
        if(dist[next.row][next.col] > 0){
           next.d = cur.d + dist[next.row][next.col];
       //    cout << "Next--> " << next.row << " "<<next.col <<" "<< next.d << endl;
           if (!inspected[next.row][next.col]) pq.push(next);
        }
      }
    }

    //clock_t end = clock();
    //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //cout<<"elapsed_secs:"<<elapsed_secs<<endl;
}
/* End of File */
