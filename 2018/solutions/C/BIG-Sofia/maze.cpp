#include<iostream>
#include<queue>
using namespace std;

char mat[127][127];
bool obh[127][127];
long long m, n, sx, sy, fx, fy, minVr;

struct kl
{
    int x;
    int y;
    int vr;
};

queue<kl> bfs;
kl sp, p, newKl;

int main(){
    cin>>m>>n;
    for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
            cin>>mat[x][y];
            if(mat[x][y]=='B'){
                sp.x=x;
                sp.y=y;
                sp.vr=0;
            }
            if(mat[x][y]=='E'){
                fx=x;
                fy=y;
            }
        }
    }
    bfs.push(sp);
    while(!bfs.empty()){
        p=bfs.front();
        bfs.pop();
        newKl.vr=p.vr+1;
        if(p.x==fx && p.y==fy){
            minVr=p.vr;
            for(int q=0;q<127;q++){
                for(int w=0;w<127;w++){
                    obh[q][w]=false;
                }
            }
            break;
        }
        if(p.x>0 && mat[p.x-1][p.y]!='#' && !obh[p.x-1][p.y]){
            newKl.x=p.x-1;
            newKl.y=p.y;
            bfs.push(newKl);
            obh[p.x-1][p.y]=true;
        }
        if(p.x<n-1 && mat[p.x+1][p.y]!='#' && !obh[p.x+1][p.y]){
            newKl.x=p.x+1;
            newKl.y=p.y;
            bfs.push(newKl);
            obh[p.x+1][p.y]=true;
        }
        if(p.y>0 && mat[p.x][p.y-1]!='#' && !obh[p.x][p.y-1]){
            newKl.x=p.x;
            newKl.y=p.y-1;
            bfs.push(newKl);
            obh[p.x][p.y-1]=true;
        }
        if(p.y<m-1 && mat[p.x][p.y+1]!='#' && !obh[p.x][p.y+1]){
            newKl.x=p.x;
            newKl.y=p.y+1;
            bfs.push(newKl);
            obh[p.x][p.y+1]=true;
        }
    }
    while(!bfs.empty()){
        bfs.pop();
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]=='#'){
                mat[i][j]='.';
                bfs.push(sp);
                while(!bfs.empty()){
                    p=bfs.front();
                    bfs.pop();
                    newKl.vr=p.vr+1;
                    if(p.x==fx && p.y==fy){
                        if(p.vr+2<minVr){minVr=p.vr+2;}
                        for(int q=0;q<127;q++){
                            for(int w=0;w<127;w++){
                                obh[q][w]=false;
                            }
                        }
                        break;
                    }
                    if(p.x>0 && mat[p.x-1][p.y]!='#' && !obh[p.x-1][p.y]){
                        newKl.x=p.x-1;
                        newKl.y=p.y;
                        bfs.push(newKl);
                        obh[p.x-1][p.y]=true;
                    }
                    if(p.x<n-1 && mat[p.x+1][p.y]!='#' && !obh[p.x+1][p.y]){
                        newKl.x=p.x+1;
                        newKl.y=p.y;
                        bfs.push(newKl);
                        obh[p.x+1][p.y]=true;
                    }
                    if(p.y>0 && mat[p.x][p.y-1]!='#' && !obh[p.x][p.y-1]){
                        newKl.x=p.x;
                        newKl.y=p.y-1;
                        bfs.push(newKl);
                        obh[p.x][p.y-1]=true;
                    }
                    if(p.y<m-1 && mat[p.x][p.y+1]!='#' && !obh[p.x][p.y+1]){
                        newKl.x=p.x;
                        newKl.y=p.y+1;
                        bfs.push(newKl);
                        obh[p.x][p.y+1]=true;
                    }
                }
                mat[i][j]='#';
                while(!bfs.empty()){
                    bfs.pop();
                }
            }
        }
    }
    cout<<minVr<<endl;
return 0;
}
/**
6 7
.....B.
.#####.
.#...#.
.#E#.#.
.###.#.
.......
*/
