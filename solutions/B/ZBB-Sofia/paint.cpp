#include <iostream>


#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

using namespace std;

struct vertical{
    short x;
    short up;
    short down;
};

struct horizontal{
    short y;
    short left;
    short right;
};

horizontal* hLines;
vertical* vLines;
short lineCount=0;

short w,h;



bool canPaint(short x,  short y, short dir){
    if(dir == LEFT || dir == RIGHT){
        for(int i=0; i<lineCount; i++){
            if(dir == LEFT && vLines[i].x == x || dir == RIGHT && vLines[i].x == x+1){
                if(vLines[i].up <= y && vLines[i].down > y) return false;
            }
        }
    } else {
        for(int i=0; i<lineCount; i++){
            if(dir == UP && hLines[i].y == y || dir == DOWN && hLines[i].y == y+1){
                if(hLines[i].left <= x && hLines[i].right > x) return false;
            }
        }
    }

    return true;
}

void color(bool* plane[], short x, short y);

short totalColored = 0;

int main(){
    cin>>w>>h;

    bool* plane[w];
    for(int i=0; i<w; i++){
        plane[i] = new bool[h];
        for(int j=0; j<h; j++) plane[i][j] = false;
    }


    short n, x, y, ws, hs;
    cin>>n;
    lineCount = n*2;
    hLines = new horizontal[n*2];
    vLines = new vertical[n*2];

    for(int i=0; i<n; i++){
        cin>>x>>y>>ws>>hs;
        hLines[i*2].y = y;
        hLines[i*2].left = x;
        hLines[i*2].right = x+ws;

        hLines[i*2+1].y = y+hs;
        hLines[i*2+1].left = x;
        hLines[i*2+1].right = x+ws;

        vLines[i*2].x = x;
        vLines[i*2].up = y;
        vLines[i*2].down = y+hs;

        vLines[i*2+1].x = x+ws;
        vLines[i*2+1].up = y;
        vLines[i*2+1].down = y+hs;
    }

    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>x>>y;
        if(plane[x][y]){
            cout<<totalColored<<endl;
        } else{
            totalColored = 0;
            for(int i=0; i<w; i++){
                plane[i] = new bool[h];
                for(int j=0; j<h; j++) plane[i][j] = false;
            }

            color(plane, x, y);
            cout<<totalColored<<endl;
        }
    }
}

void color(bool* plane[], short x, short y){
    if(plane[x][y] == true) return;
    plane[x][y] = true;
    totalColored++;

    if(x-1>= 0 && canPaint(x, y, LEFT)) color(plane, x-1, y);
    if(x+1<w && canPaint(x, y, RIGHT)) color(plane, x+1, y);
    if(y-1>=0 && canPaint(x, y, UP)) color(plane, x, y-1);
    if(y+1<h && canPaint(x, y, DOWN)) color(plane, x, y+1);
}
