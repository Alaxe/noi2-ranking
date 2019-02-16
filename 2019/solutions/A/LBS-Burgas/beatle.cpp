#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 131072

using namespace std;

class Line{
public:
    int x;
    int y;
    int d;

    Line(){
        x = MAXN;
        y = MAXN;
        d = MAXN;
    }

    Line(int x, int y, int d){
        this->x = x;
        this->y = y;
        this->d = d;
    }
};

int main(){
    int N;
    vector<Line> lines;
    int x, y, d;
    int xMax, yMax;
    scanf("%d", &N);
    while(N--){
        scanf("%d%d%d", &x, &y, &d);
        xMax = max(xMax, x);
        yMax = max(yMax, y);
        lines.push_back(Line(x, y, d));
    }

    int ans[MAXN];//fill with 0
    int val = 0;
    for(int j = 1; j <= yMax; j++){
    for(int i = 0; i < lines.size(); i++){
        if(lines[i].y == j){
            val = min(ans[lines[i].x], ans[lines[i].x + lines[i].d + 1]) + 1;
            //fill ans from lines[i].x+1 to lines[i].x + d
            for(int m = lines[i].x; m <= lines[i].x + lines[i].d; m++) {ans[m] = val;}
            swap(lines[i], lines.back());
            lines.pop_back();
        }
    }}

    int T, l;
    scanf("%d", &T);
    while(T--){
        scanf("%d", l);
        printf("%d", ans[l]);
    }
    return 0;
}
