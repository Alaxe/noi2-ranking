#include<iostream>
#include<vector>
using namespace std;
struct edge {
    int to;
    bool art;
    int rev;
};
vector <edge> a[100001];
int in[100001],up[100001],used[100001],num=0;
long long int cnt;
void dfs (int vr, int fath) {
    in[vr]=num++; up[vr]=in[vr];
    used[vr]=1;
    int i;
    for (i=0; i<a[vr].size(); i++) {
        if (a[vr][i].to==fath) continue;
        if (used[a[vr][i].to]==0) {
           dfs(a[vr][i].to,vr);
           if (up[a[vr][i].to]>in[vr]) {
              a[vr][i].art=1;
              a[a[vr][i].to][a[vr][i].rev].art=1;
              }
           up[vr]=min(up[vr],up[a[vr][i].to]);
           }
        else up[vr]=min(up[vr],in[a[vr][i].to]);
        }
}
void dfs2 (int vr) {
    if (used[vr]==1) return ;
    used[vr]=1; cnt++;
    int i;
    for (i=0; i<a[vr].size(); i++) {
        if (a[vr][i].art==1) continue;
        dfs2(a[vr][i].to);
        }
}
int main () {
    long long int ans=0;
    int n,m,i,x,y;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m ;
    for (i=0; i<m; i++) {
        cin >> x >> y ;
        x--; y--;
        a[x].push_back({y,0,a[y].size()});
        a[y].push_back({x,0,a[x].size()-1});
        }
    dfs(0,-1);
    for (i=0; i<n; i++) {
        used[i]=0;
        }
    for (i=0; i<n; i++) {
        cnt=0;
        dfs2(i);
        ans+=cnt*(cnt-1)/2;
        }
    cout << ans ;
    cout << endl ;
    return 0;
}
