#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#define pb push_back
#define mp make_pair
using namespace std;
const int N=1e3+5;

int n;

struct point{
  double x,y;

}p[N];


map <pair <double,double>,int> mymap;

pair <double,double> get_line(point pp,point qq)
{

    double a,b;

    a=(pp.y-qq.y)/(pp.x-qq.x);
    b=pp.y- a*pp.x;

    return mp(a,b);
}

int ans;
void solve(int ind)
{
   int i;
   int ordinata=1;

   for(i=1;i<=n;i++)
   {
       if(i == ind)
        continue;

       if(p[i].x == p[ind].x)
       {
           ordinata++;
           ans=max(ans,ordinata);

           continue;
       }

       pair <double,double> line=get_line(p[ind],p[i]);

      // cerr<<line.first<<" "<<line.second<<endl;

       mymap[line]++;
       ans=max(ans,mymap[line]+1);
   }
}

int main()
{
   //freopen("input_lines.txt","r",stdin);

   int i;

   scanf("%d", &n);
   for(i=1;i<=n;i++)
   {
       scanf("%lf%lf", &p[i].x, &p[i].y);
   }

   for(i=1;i<=n;i++)
   {
       mymap.clear();
       solve(i);
   }

   printf("%d\n", ans);

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
