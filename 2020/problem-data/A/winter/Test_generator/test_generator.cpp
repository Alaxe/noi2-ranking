/* test generator uses testlib.h: https://github.com/MikeMirzayanov/testlib/blob/master/testlib.h
   arguments:
   - first - name of the test that will be generated
   - second - number of vertices
   - third - number of edges
   - fourth - number of bridges
   - fifth - type of test that will be generated
             = 0 - random graph
             = 1 - graph
   - sixth, seventh, eighth, ... - used for seed for registerGen */
#include<iostream>
#include "testlib.h"
#include<vector>
#include<map>
using namespace std;
map <pair <int, int>, bool> edges;
map <pair <int, int>, bool>::iterator it;
vector <int> a[100001],comp[100001],vers,perm,pos,up,down;
vector <pair <int, int> > perm2,output;
int in[100001],min1[1000001],used[100001],edg[100001],cnt,num;
void dfs (int vr, int fath) {
    up.push_back(vr);
    used[vr]=1;
    in[vr]=num++;
    min1[vr]=in[vr];
    int i,ind,x,y,special=-1;
    //cout << vr << " " << fath << endl ;
    for (i=0; i<a[vr].size(); i++) {
        if (a[vr][i]==fath) continue;
        if (used[a[vr][i]]==0) {
           ind=down.size();
           dfs(a[vr][i],vr);
           min1[vr]=min(min1[vr],min1[a[vr][i]]);
           if ((min1[a[vr][i]]>in[vr])&&(a[vr][i]!=special)) {
              if ((fath==-1)&&(down.size()-ind==1)) {
                 for (;;) {
                     if (i!=0) x=a[vr][rnd.next(i)], y=a[vr][i];
                     else x=a[vr][1+rnd.next(a[vr].size()-1)], y=a[vr][i], special=x;
                     //cout << a[vr][i] << " " << x << " " << y << " " << edges.count({min(x,y),max(x,y)}) << "   ";
                     if (edges.count({min(x,y),max(x,y)})==1) continue;
                     a[x].push_back(y);
                     a[y].push_back(x);
                     edges[{min(x,y),max(x,y)}]=1;
                     cnt++;
                     //cout << edges.size() << " " << cnt << endl ;
                     break;
                     }
                 continue;
                 }
              for (;;) {
                  x=up[rnd.next(up.size())]; y=down[ind+rnd.next(down.size()-ind)];
                  //cout << a[vr][i] << " " << x << " " << y << " " << edges.count({min(x,y),max(x,y)}) << "   ";
                  if (edges.count({min(x,y),max(x,y)})==1) continue;
                  a[x].push_back(y);
                  a[y].push_back(x);
                  edges[{min(x,y),max(x,y)}]=1;
                  cnt++;
                  min1[vr]=min(min1[vr],in[x]);
                  break;
                  }
              }
           }
        else min1[vr]=min(min1[vr],in[a[vr][i]]);
        }
    down.push_back(vr);
    up.pop_back();
}
bool cmp (vector <int>& ex1, vector <int>& ex2) {
    if (ex1.size()<ex2.size()) return true;
    return false;
}
int main (int argc, char** argv) {
    if (argc==1) return 0;
    FILE *fout=fopen(argv[1],"w");
    int n,m,k,type,i,j,h,x,y,prev,ind,sum,fl;
    registerGen(argc,argv,1);
    n=atoi(argv[2]); m=atoi(argv[3]);
    k=atoi(argv[4]); type=atoi(argv[5]);
    for (i=0; i<n; i++) {
        vers.push_back(i);
        }
    shuffle(vers.begin(),vers.end());
    if (type==0) {
       for (i=1; i<n; i++) {
           x=vers[rnd.next(i)]; y=vers[i];
           edges[{min(x,y),max(x,y)}]=1;
           cnt++;
           }
       for (i=1; i<=5000000/n; i++) {
           for (j=0; j<n; j++) {
               perm.push_back(vers[j]);
               }
           }
       shuffle(perm.begin(),perm.end());
       for (i=0; i<perm.size(); i+=2) {
           x=perm[i]; y=perm[i+1];
           if (x==y) continue;
           if (edges.count({min(x,y),max(x,y)})==1) continue;
           edges[{min(x,y),max(x,y)}]=1;
           cnt++;
           if (cnt==m) break;
           }
       }
    else {
        for (i=1; i<n; i++) {
            pos.push_back(i);
            }
        shuffle(pos.begin(),pos.end());
        if (k>0) sort(pos.begin(),pos.begin()+k);
        prev=0;
        for (i=0; i<k; i++) {
            for (j=0; j<pos[i]-prev; j++) {
                comp[i].push_back(vers[prev+j]);
                }
            prev=pos[i];
            }
        for (i=0; i<n-prev; i++) {
            comp[k].push_back(vers[prev+i]);
            }
        sort(comp,comp+k+1,cmp);
        ind=k;
        for (i=0; i<k; i++) {
            if (comp[i].size()==2) {
               if (comp[ind].size()==3) ind--;
               comp[i].push_back(comp[ind].back());
               comp[ind].pop_back();
               }
            }
        for (i=0; i<=k; i++) {
            if (comp[i].size()==2) cout << "!";
            for (j=1; j<comp[i].size(); j++) {
                x=comp[i][rnd.next(j)]; y=comp[i][j];
                a[x].push_back(y);
                a[y].push_back(x);
                edges[{min(x,y),max(x,y)}]=1;
                cnt++;
                }
            up.clear(); down.clear();
            dfs(comp[i][0],-1); //cout << edges.size() << " " << cnt << endl ;
            }
        pos.clear();
        for (i=1; i<=k; i++) {
            ind=rnd.next(i);
            x=comp[ind][rnd.next(comp[ind].size())]; y=comp[i][rnd.next(comp[i].size())];
            edges[{min(x,y),max(x,y)}]=1;
            cnt++;
            }
        for (i=0; i<=k; i++) {
            perm.clear();
            for (j=1; j<=500; j++) {
                for (h=0; h<comp[i].size(); h++) {
                    perm.push_back(comp[i][h]);
                    }
                }
            shuffle(perm.begin(),perm.end());
            for (j=0; j<perm.size(); j+=2) {
                x=perm[j]; y=perm[j+1];
                if ((x==y)||(edges.count({min(x,y),max(x,y)})==1)) continue;
                perm2.push_back({min(x,y),max(x,y)});
                }
            }
        shuffle(perm2.begin(),perm2.end());
        for (i=0; i<perm2.size(); i++) {
            x=perm2[i].first; y=perm2[i].second;
            if (edges.count({x,y})==1) continue;
            edges[{x,y}]++;
            cnt++;
            if (cnt==m) break;
            }
        }
    for (it=edges.begin(); it!=edges.end(); it++) {
        output.push_back(it->first);
        }
    cout << edges.size() << " " << cnt << endl ;
    shuffle(output.begin(),output.end());
    fprintf(fout,"%d %d\n",n,output.size());
    for (i=0; i<output.size(); i++) {
        if (rnd.next(2)==0) fprintf(fout,"%d %d\n",output[i].second+1,output[i].first+1);
        else fprintf(fout,"%d %d\n",output[i].first+1,output[i].second+1);
        }
    return 0;
}
