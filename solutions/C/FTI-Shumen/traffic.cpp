#include<iostream>
using namespace std;
struct dir {
    int f,g;
};
const long long inf=(1<<31)-1;
char c[640][640];
long long n,m,i,j,a,b,minsum=inf,used[640][640];
dir direct[4]= {
    {-1,0},{1,0},{0,1},{0,-1}
},par;
void path(int x,int y,dir par) {
    if(x==n||y==m||y==1||x==1) {
        if(used[x][y]<minsum)minsum=used[x][y];
        return;
    } 
    par.f=x;
    par.g=y;
    for(int i=0; i<4; i++) {
        int x1,y1;
        x1=x+direct[i].f;
        y1=y+direct[i].g;
        if(x1<=n&&x1>0&&y1<=m&&y1>0) {
            if(c[x1][y1]!='*'&&!used[x1][y1]) {
                used[x1][y1]=used[x][y]+(int)(c[x1][y1]-'A'+1);
                path(x1,y1,par);
            } else if(c[x1][y1]!='*'&&used[x1][y1]>used[x][y]+(int)(c[x1][y1]-'A'+1)&&par.f!=x1&&par.g!=y1) {
                used[x1][y1]=used[x][y]+(int)(c[x1][y1]-'A'+1);
                path(x1,y1,par);
            }
        }
    }  

}
int main() {
    cin>>n>>m;
    for( i=1; i<=n; i++)
        for(j=1; j<=m; j++) {
            cin>>c[i][j];
            if(c[i][j]=='#') {
                a=i;
                b=j;
                used[i][j]=1;
            }
        }
        par.f=a;
        par.g=b;
    path(a,b,par);
    cout<<minsum-1<<endl;
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
