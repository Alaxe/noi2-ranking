#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int used[100001],vr1,vr2,fin;
vector <int> a[100001];
void dfs (int vr) {
    if (used[vr]==1) return ;
    used[vr]=1;
    if (used[fin]==1) return ;
    int i;
    for (i=0; i<a[vr].size(); i++) {
        if ((vr+a[vr][i]==vr1+vr2)&&(vr*a[vr][i]==vr1*vr2)) continue;
        dfs(a[vr][i]);
        if (used[fin]==1) return ;
        }
}
int main () {
    int n,m,i,j,h,k,x,y,fl;
    long long int cnt=0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m ;
    for (i=0; i<m; i++) {
        cin >> x >> y ;
        x--; y--;
        a[x].push_back(y);
        a[y].push_back(x);
        }
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            fl=0;
            for (h=0; h<n; h++) {
                for (k=0; k<a[h].size(); k++) {
                    if (h>a[h][k]) continue;
                    vr1=h; vr2=a[h][k];
                    memset(used,0,sizeof(used));
                    fin=j; dfs(i);
                    if (used[fin]==0) {
                       fl++;
                       break;
                       }
                    }
                if (fl!=0) break;
                }
            if (fl==0) cnt++;
            }
        }
    cout << cnt ;
    cout << endl ;
    return 0;
}
