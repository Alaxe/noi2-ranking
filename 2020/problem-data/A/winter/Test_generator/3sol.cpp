#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
namespace third_sol {
    int used[100001],comp[100001],num,vr1,vr2;
    vector <int> a[100001];
    bool ans[1001][1001];
    void dfs (int vr) {
        if (used[vr]==1) return ;
        used[vr]=1; comp[vr]=num;
        int i;
        for (i=0; i<a[vr].size(); i++) {
            if ((vr+a[vr][i]==vr1+vr2)&&(vr*a[vr][i]==vr1*vr2)) continue;
            dfs(a[vr][i]);
            }
    }
    int solution (char* name1, char* name2) {
        FILE *fin=fopen(name1,"r"),*fout=fopen(name2,"w");
        int n,m,i,j,h,k,x,y;
        long long int cnt=0;
        fscanf(fin,"%d%d",&n,&m);
        for (i=0; i<m; i++) {
            fscanf(fin,"%d%d",&x,&y);
            x--; y--;
            a[x].push_back(y);
            a[y].push_back(x);
            }
        for (i=0; i<n; i++) {
            for (j=0; j<a[i].size(); j++) {
                if (i>a[i][j]) continue;
                vr1=i; vr2=a[i][j];
                memset(used,0,sizeof(used));
                num=0;
                for (h=0; h<n; h++) {
                    if (used[h]==0) {
                       dfs(h);
                       num++;
                       }
                    }
                for (h=0; h<n; h++) {
                    for (k=h+1; k<n; k++) {
                        if (comp[h]!=comp[k]) ans[h][k]=1;
                        }
                    }
                }
            }
        for (i=0; i<n; i++) {
            for (j=i+1; j<n; j++) {
                if (ans[i][j]==0) cnt++;
                }
            }
        fprintf(fout,"%lld\n",cnt);
        return 0;
    }
}
