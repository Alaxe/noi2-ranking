#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct state {
    int x,y,b, time;
};

int A[100][100];
int B[100][100];

int m,n;    

int main() {
    cin>>m>>n;
    vector<string> maze(m);
    state start, end;
    for(int i=0; i<m; i++) {
        string s;
        cin>>s;
        maze[i] = s;
        for(int j=0; j<n; j++) {
            if (s[j]=='B') {start.x=i; start.y=j;}
            if (s[j]=='E') {end.x=i; end.y=j;maze[i][j]='.';}
        }
    }

    start.b = 0;
    start.time = 0;
    
    queue<state> q;
    q.push(start);
    while (!q.empty()) {
        state p = q.front();
        
        q.pop();
        if (p.b==0 && A[p.x][p.y]==1) continue;
        if (p.b==1 && B[p.x][p.y]==1) continue;
        if (p.b==0) A[p.x][p.y]=1;
        B[p.x][p.y]=1;
        if (p.x==end.x && p.y==end.y) {
            cout<<p.time<<endl;
            if (q.empty()) {
                q.push(p);
            }
            break;
        }
        if (p.x>0) {
            state r;
            r.x = p.x-1;
            r.y = p.y;
            r.b = p.b;
            if (maze[r.x][r.y]=='.' && A[r.x][r.y]==0) {
                if (r.b==0 || B[r.x][r.y]==0) {
                    r.time = p.time+1;
                    q.push(r);
                } 
            }
            if (maze[r.x][r.y]=='#' && p.b==0) {
                r.time = p.time+3;
                r.b++;
                q.push(r);
            }
        }
        if (p.y>0) {
            state r;
            r.x = p.x;
            r.y = p.y-1;
            r.b = p.b;
            if (maze[r.x][r.y]=='.' && A[r.x][r.y]==0) {
                if (r.b==0 || B[r.x][r.y]==0) {
                    r.time = p.time+1;
                    q.push(r);
                } 
            }
            if (maze[r.x][r.y]=='#' && p.b==0) {
                r.time = p.time+3;
                r.b++;
                q.push(r);
            } 
        }
        if (p.x<m-1) {
            state r;
            r.x = p.x+1;
            r.y = p.y;
            r.b = p.b;
            if (maze[r.x][r.y]=='.' && A[r.x][r.y]==0) {
                if (r.b==0 || B[r.x][r.y]==0) {
                    r.time = p.time+1;
                    q.push(r);
                } 
            }
            if (maze[r.x][r.y]=='#' && p.b==0) {
                r.time = p.time+3;
                r.b++;
                q.push(r);
            }
        }
        if (p.y<n-1) {
            state r;
            r.x = p.x;
            r.y = p.y+1;
            r.b = p.b;
            if (maze[r.x][r.y]=='.' && A[r.x][r.y]==0) {
                if (r.b==0 || B[r.x][r.y]==0) {
                    r.time = p.time+1;
                    q.push(r);
                } 
            }
            if (maze[r.x][r.y]=='#' && p.b==0) {
                r.time = p.time+3;
                r.b++;
                q.push(r);
            }
        }
    }
    
    if (q.empty()) cout<<-1<<endl;
    
    return 0;
}