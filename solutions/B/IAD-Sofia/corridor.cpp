#include <iostream>
#include <algorithm>
using namespace std;
struct seg
{
    int x, y;
    int len;
    seg()
    {
        len = 0;
    }
};
seg vert[100002];
bool operator<(seg a, seg b)
{
    if(a.y == b.y) return a.x > b.x;
    return a.y < b.y;
}
unsigned long long l, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    for(int i = 1; i < n; i ++)
    {
        int tx, ty;
        cin >> tx >> ty;
        if(tx == x)
        {
            if(l > 0 && vert[l-1].x == tx) vert[l-1].len += ty-y;
            else
            {
                vert[l].y = y;
                vert[l].len = ty-y;
                vert[l ++].x = x;
            }
        }
        x = tx;
        y = ty;
    }
    for(int i = 0; i < l; i ++)
    {
        if(vert[i].len < 0)
        {
            vert[i].y += vert[i].len;
            vert[i].len = -vert[i].len;
        }
    }
    sort(vert, vert+l);
    int r = 0;
    for(int i = 0; i < l; i ++)
    {
        if(vert[i].y+vert[i].len > r)
        {
            ans += (unsigned long long)(vert[i].y+vert[i].len - r)*(unsigned long long)(w-vert[i].x);
            r = vert[i].y+vert[i].len;
        }
    }
    cout << ans << endl;
}
