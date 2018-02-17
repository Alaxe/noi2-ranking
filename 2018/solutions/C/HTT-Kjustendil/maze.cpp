#include <iostream>
#include <string>

using namespace std;

int main() {
    int startM, startN, finishM, finishN;
    int M, N;
    cin>>M>>N;
    int maze[M][N];
    char mazem[M][N];
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin>>mazem[i][j];
            if(mazem[i][j]=='.') {
                maze[M][N]=1;
            }else if(mazem[i][j]=='#') {
                maze[i][j] = 3;
            }else if(mazem[i][j]=='B') {
                startM = i;
                startN = j;
                maze[i][j] = 0;
            }else if(mazem[i][j]=='E') {
                finishM = i;
                finishN = j;
                maze[i][j] = 1;
            }
        }
    }
    cout<<"-1"<<endl;
}
