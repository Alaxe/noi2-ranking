#include <iostream>
#include <queue>

using namespace std;

char maze[100][100];
long long tsp[100][100];
bool vzrivqvanoLiE[100][100];
bool obhodenLiE[100][100];

int main() {
    cin.tie();
    ios_base::sync_with_stdio(false);
    long long N,M,finalX,finalY;
    queue<int> opashka;
    cin >> N >> M;
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < M; ++j) {
            cin >> maze[i][j];
            if (maze[i][j]=='B'){
                tsp[i][j] = 0;
                opashka.push(i*100+j);
            }else{
                if (maze[i][j]=='E') {
                    finalY = i;
                    finalX = j;
                }
                tsp[i][j] = 222222;
            }
        }
    }
    while (!opashka.empty()) {
        long long z = opashka.front();
        long long x = z % 100;
        long long y = z / 100;
        if (x!=0 && !obhodenLiE[y][x-1]) {
            if (maze[y][x-1]!='#') {
                if (tsp[y][x-1]>tsp[y][x]+1) {
                    tsp[y][x-1] = tsp[y][x]+1;
                    vzrivqvanoLiE[y][x-1] = vzrivqvanoLiE[y][x];
                }else {
                    if (tsp[y][x-1]==tsp[y][x]+1 && !vzrivqvanoLiE[y][x]){
                        vzrivqvanoLiE[y][x-1] = false;
                    }
                }
            }else{
                if (tsp[y][x-1]>tsp[y][x]+3 && !vzrivqvanoLiE[y][x]) {
                    tsp[y][x-1] = tsp[y][x]+3;
                    vzrivqvanoLiE[y][x-1] = true;
                }
            }
            opashka.push(y*100+x-1);
        }
        if (x!=M-1 && !obhodenLiE[y][x+1]) {
            if (maze[y][x+1]!='#') {
                if (tsp[y][x+1]>tsp[y][x]+1) {
                    tsp[y][x+1] = tsp[y][x]+1;
                    vzrivqvanoLiE[y][x+1] = vzrivqvanoLiE[y][x];
                }else {
                    if (tsp[y][x+1]==tsp[y][x]+1 && !vzrivqvanoLiE[y][x]){
                        vzrivqvanoLiE[y][x+1] = false;
                    }
                }
            }else{
                if (tsp[y][x+1]>tsp[y][x]+3 && !vzrivqvanoLiE[y][x]) {
                    tsp[y][x+1] = tsp[y][x]+3;
                    vzrivqvanoLiE[y][x+1] = true;
                }
            }
            opashka.push(y*100+x+1);
        }
        if (y!=0  && !obhodenLiE[y-1][x]) {
            if (maze[y-1][x]!='#') {
                if (tsp[y-1][x]>tsp[y][x]+1) {
                    tsp[y-1][x] = tsp[y][x]+1;
                    vzrivqvanoLiE[y-1][x] = vzrivqvanoLiE[y][x];
                }else {
                    if (tsp[y-1][x]==tsp[y][x]+1 && !vzrivqvanoLiE[y][x]){
                        vzrivqvanoLiE[y-1][x] = false;
                    }
                }
            }else{
                if (tsp[y-1][x]>tsp[y][x]+3 && !vzrivqvanoLiE[y][x]) {
                    tsp[y-1][x] = tsp[y][x]+3;
                    vzrivqvanoLiE[y-1][x] = true;
                }
            }
            opashka.push(y*100+x-100);
        }
        if (y!=N-1  && !obhodenLiE[y+1][x]) {
            if (maze[y+1][x]!='#') {
                if (tsp[y+1][x]>tsp[y][x]+1) {
                    tsp[y+1][x] = tsp[y][x]+1;
                    vzrivqvanoLiE[y+1][x] = vzrivqvanoLiE[y][x];
                }else {
                    if (tsp[y+1][x]==tsp[y][x]+1 && !vzrivqvanoLiE[y][x]){
                        vzrivqvanoLiE[y+1][x] = false;
                    }
                }
            }else{
                if (tsp[y+1][x]>tsp[y][x]+3 && !vzrivqvanoLiE[y][x]) {
                    tsp[y+1][x] = tsp[y][x]+3;
                    vzrivqvanoLiE[y+1][x] = true;
                }
            }
            opashka.push(y*100+x+100);
        }
        obhodenLiE[y][x] = true;
        opashka.pop();
    }
    if (tsp[finalY][finalX] == 222222) {
        cout << -1;
    }else{
        cout << tsp[finalY][finalX];
    }
    cout << "\n";
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
