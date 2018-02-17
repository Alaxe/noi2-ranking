#include <iostream>
using namespace std;
int w, h, n, t;
int x[11001];
struct rect
{
    int w, h;
    int idx;
    rect()
    {
        idx = -1;
    }
} inp[11001][11001];
long long ans[11001];
long long s[11002];
int pos[11001][11001];
int bot[11001][3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> h;
    cin >> n;
    for(int i = 0; i < 11001; i ++) x[i] = -2;
    for(int i = 0; i < n; i ++)
    {
        int tx, ty, tw, th;
        cin >> tx >> ty >> tw >> th;
        inp[tx][ty].w = tw;
        inp[tx][ty].h = th;
        inp[tx][ty].idx = i;
    }
    int curr = -1;
    for(int i = 0; i < h; i ++)
    {
        for(int j = 0; j < w; j ++)
        {
            if(inp[j][i].idx >= 0)
            {
                bot[inp[j][i].idx][0] = j;
                bot[inp[j][i].idx][1] = j+inp[j][i].w;
                bot[inp[j][i].idx][2] = i+inp[j][i].h-1;
                x[j] = inp[j][i].idx;
                x[j+inp[j][i].w] = curr;
                curr = inp[j][i].idx;
            }
            if(x[j] >= -1) curr = x[j];
            pos[j][i] = curr;
            if(curr >= 0) s[curr] ++;
            else s[11001] ++;
            if(curr > -1 && bot[curr][2] == i && j >= bot[curr][0] && j <= bot[curr][1]) x[j] = -2;
            //cout << pos[j][i] << " ";
        }
        //cout << endl;
    }
    cin >> t;
    for(int i = 0; i < t; i ++)
    {
        int tx, ty;
        cin >> tx >> ty;
        ans[i] = s[pos[tx][ty]];
        if(pos[tx][ty] < 0) ans[i] = s[11001];
    }
    for(int i = 0; i < t; i ++) cout << ans[i] << endl;
}

