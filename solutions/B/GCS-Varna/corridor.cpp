#include <iostream>
#include <algorithm>
#define MAXN 100002
using namespace std;

struct point{
    int x, y;
};

bool cmp(point a, point b)
{
    return a.y < b.y;
}

int n, i, indin, indy, ind;
unsigned long long w, h, curx, cury, area;
point in[MAXN], insort[MAXN], res[MAXN];

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

cin >> w >> h;
cin >> n;

for(i = 0; i < n; i ++)
{
    cin >> in[i].x >> in[i].y;
    insort[i] = in[i];
}

sort(insort, insort + n, cmp);

indin = 0; indy = 0; ind = 0;
while(indin<n && indy<n)
{
    if(in[indin].x == insort[indy].x && in[indin].y == insort[indy].y) {indin ++; res[ind] = insort[indy]; indy ++; ind ++;}
    else if(in[indin].y > insort[indy].y) indy ++;
    else if(in[indin].y == insort[indy].y) {res[ind] = insort[indy]; ind ++; indy ++;}
    else if(in[indy].y > insort[indin].y) indin ++;

    //cout << "indy = " << indy << " and indin = " << indin << "\n";
}

//cout << "result \n";
//for(i = 0; i < ind; i ++) cout << res[i].x << " " << res[i].y << "\n";
curx = w-res[0].x; area = 0;
for(i = 1; i < ind; i ++)
{
    if(res[i].x == res[i-1].x)
    {
        cury = res[i].y - res[i-1].y;
        area = area + curx*cury;
    }
    else if(res[i].y == res[i-1].y)
        curx = curx - (res[i].x - res[i-1].x);
    else
    {
        if(res[i].y > res[i-1].y) cury = res[i].y - res[i-1].y;
        else cury = res[i-1].y - res[i].y;

        if(res[i].x > res[i-1].x) curx = curx + res[i].x - res[i-1].x;
        else curx = curx + res[i-1].x - res[i].x;

        area = area + curx*cury;
    }

    //cout << "curx = " << curx << " cury = " << cury << "\n";
}

cout << area << "\n";

return 0;
}

/**
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
