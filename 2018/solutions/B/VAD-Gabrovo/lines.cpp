#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int n;
struct Point
{
    int x, y;
};
Point a[1024];
//vector <vector <int> > v;
//vector <vector <int> > equal_x;
//vector <vector <int> > equal_y;

int main ()
{
    int maxx=0, maxy=0, maxd=0;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i].x>>a[i].y;
    for (int i=0; i<n-2; i++)
        for (int j=i+1; j<n-1; j++)
        {
            if (a[i].x==a[j].x)
            {
                int br=2;
                for (int k=j+1; k<n; k++)
                    if (a[k].x==a[i].x)
                        br++;
                maxx=max (maxx, br);
            }
            else if (a[i].y==a[j].y)
            {
                int br=2;
                for (int k=j+1; k<n; k++)
                    if (a[k].y==a[i].y)
                        br++;
                maxy=max (maxy, br);
            }
            else
            {
                int br=2;
                for (int k=j+1; k<n; k++)
                    if ((a[i].x-a[j].x)*(a[i].y-a[k].y)==(a[i].y-a[j].y)*(a[i].x-a[k].x))
                        br++;
                maxd=max (maxd, br);
            }
        }
    cout<<max (max (maxx, maxy), maxd)<<endl;
    return 0;
}
