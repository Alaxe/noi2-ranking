#include <iostream>
#include <queue>
using namespace std;
queue <int> q;
bool used[10001];
int ans[10001];
int ans1[10001];
char t[101][101];
int mo[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int dfs(int cur, int e) {
    q.push(cur);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            ans1[i*m+j]=-1;
        }
    }
    int x, i, j, i1, j1;
    ans1[cur]=0;
    while (!q.empty()) {
        x=q.front();
        q.pop();
        i=x/m;
        j=x%m;
        for (int k=0;k<4;k++) {
            i1=i+mo[k][0];
            j1=j+mo[k][1];
            if (i1==-1 or j1==-1 or i1==n or j1==m or t[i1][j1]=='#' or ans1[i1*m+j1]>-1) continue;
            ans1[i1*m+j1]=ans1[x]+1;
            q.push(i1*m+j1);
        }
    }
    return ans1[e];
}
int main () {
    cin >> n >> m;
    int start, krai;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> t[i][j];
            if (t[i][j]=='B') {
                start=i*m+j;
                t[i][j]='.';
            }
            if (t[i][j]=='E') {
                krai=i*m+j;
                t[i][j]='.';
            }
            ans[i*m+j]=-1;
        }
    }
    q.push(start);
    ans[start]=0;
    int x, i1, j1, i, j;
    while (!q.empty()) {
        x=q.front();
        q.pop();
        i=x/m;
        j=x%m;
        for (int k=0;k<4;k++) {
            i1=i+mo[k][0];
            j1=j+mo[k][1];
            if (i1==-1 or j1==-1 or i1==n or j1==m or t[i1][j1]=='#' or ans[i1*m+j1]>-1) continue;
            ans[i1*m+j1]=ans[x]+1;
            q.push(i1*m+j1);
        }
    }
    int s=ans[krai], s1;
    if (s==-1) s=n*m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (t[i][j]=='#') {
                s1=n*m;
                for (int k=0;k<4;k++) {
                    i1=i+mo[k][0];
                    j1=j+mo[k][1];
                    if (i1==-1 or j1==-1 or i1==n or j1==m or t[i1][j1]=='#' or ans[i1*m+j1]==-1) continue;
                    if (ans[i1*m+j1]<s1) {
                        s1=ans[i1*m+j1];
                        x=i1*m+j1;
                    }
                }
                s1+=4;
                for (int k=0;k<4;k++) {
                    i1=i+mo[k][0];
                    j1=j+mo[k][1];
                    if (i1==-1 or j1==-1 or i1==n or j1==m or t[i1][j1]=='#') continue;
                    int sum=dfs(i1*m+j1,krai);
                    if (sum==-1) continue;
                    if (sum+s1<s) s=sum+s1;
                }
            }
        }
    }
    if (s==n*m) s=-1;
    cout << s << endl;
    return 0;
}
