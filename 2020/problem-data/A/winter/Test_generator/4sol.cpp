#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
namespace fourth_sol {
    int used[100001],vr1,vr2,end1;
    vector <int> a[100001];
    void dfs (int vr) {
        if (used[vr]==1) return ;
        used[vr]=1;
        if (used[end1]==1) return ;
        int i;
        for (i=0; i<a[vr].size(); i++) {
            if ((vr+a[vr][i]==vr1+vr2)&&(vr*a[vr][i]==vr1*vr2)) continue;
            dfs(a[vr][i]);
            if (used[end1]==1) return ;
            }
    }
    int solution (char* name1, char* name2) {
        FILE *fin=fopen(name1,"r"),*fout=fopen(name2,"w");
        int n,m,i,j,h,k,x,y,fl;
        long long int cnt=0;
        fscanf(fin,"%d%d",&n,&m);
        for (i=0; i<m; i++) {
            fscanf(fin,"%d%d",&x,&y);
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
                        end1=j; dfs(i);
                        if (used[end1]==0) {
                           fl++;
                           break;
                           }
                        }
                    if (fl!=0) break;
                    }
                if (fl==0) cnt++;
                }
            }
        fprintf(fout,"%lld\n",cnt);
        return 0;
    }
}
