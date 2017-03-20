#include<iostream>
using namespace std;

const int N=10001;
struct Rect{int x, y, dx, dy; int u;};
Rect r[N];
int n;
int np;

int up(int x, int y)
{
  int ms=r[0].dx*r[0].dy;
  int i0=0;
  for(int i=0;i<=n;i++)
  {
    if(r[i].x < x && x < r[i].x+r[i].dx)
    if(r[i].y < y && y < r[i].y+r[i].dy)
    if(r[i].dx*r[i].dy < ms) {ms=r[i].dx*r[i].dy; i0=i;}
  }
  return i0;
}


int main()
{
  r[0].x=r[0].y=0;
  cin >> r[0].dx >> r[0].dy;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    cin >> r[i].x >> r[i].y >> r[i].dx >> r[i].dy;
  }

  r[0].u=-1;
  for(int i=1;i<=n;i++) r[i].u=up(r[i].x,r[i].y);

  cin >> np;
  for(int j=1;j<=np;j++)
  {
    int x,y;
    cin >> x >> y;
    int k=up(x,y);
    int s=r[k].dx*r[k].dy;
    for(int i=1;i<=n;i++)
     if(k==r[i].u) s = s - r[i].dx*r[i].dy;
    cout << s << endl;
  }


}
