#include<iostream>
#include<math.h>

using namespace std;

const int MAXN=1000;
const int MAXX=100+100;
const int MAXY=100+100;
int n;
struct cordinates
{
    int x, y;
};
cordinates c[MAXN+40];
bool field[MAXX+40][MAXY+40];
int maxp;

void input()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>c[i].x>>c[i].y;
        c[i].x+=100;
        c[i].y+=100;
        field[c[i].x][c[i].y]=1;
    }
}

void output()
{
    cout<<maxp<<endl;
}

int find_points(int lx, int ly, int x, int y)
{
    int counter=0;
    int xh, yh;
    int temp;
    if (lx>ly) temp=ly;
    else temp=lx;
    for (temp/=2; temp>1; temp--)
    {
        if (lx%temp==0 && ly%temp==0)
        {
            lx/=temp;
            ly/=temp;
        }
    }
    xh=x;
    yh=y;
    while (xh<=MAXX && yh<=MAXY)
    {
        if (field[xh][yh]) counter++;
        xh+=lx;
        yh+=ly;
    }
    xh=x-lx;
    yh=y-ly;
    while (xh>=0 && yh>=0)
    {
        if (field[xh][yh]) counter++;
        xh-=lx;
        yh-=ly;
    }
    return counter;
}

void solve()
{
    int temp;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            temp=find_points(fabs(c[i].x-c[j].x), fabs(c[i].y-c[j].y), c[i].x, c[i].y);
            if (maxp<temp) maxp=temp;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    output();
    return 0;
}

/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/