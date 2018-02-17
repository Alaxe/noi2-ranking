#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

const int N_max=10000;
int n;
pair<int, int> a[N_max];
map<pair<int, int>, int> s;

int main()
{

 cin >> n;
 for(int i=1;i<=n;i++)
 {
   int x; cin >> x;
   int y; cin >> y;
   a[i]=pair<int, int>(x,y);
 }

 int glomax=0;
 for(int i=1;i<=n;i++)
 {
     int curmax=0;
     int x0=a[i].first;
     int y0=a[i].second;
     s.clear();
     for(int j=1;j<=n;j++)
     if(i!=j)
     {
       int x=a[j].first;
       int y=a[j].second;
       int dx=x-x0;
       int dy=y-y0;
       if(dx==0)dy=1;
       else if(dy==0)dx=1;
       else
       {
         int d=__gcd(abs(dx),abs(dy));
         dx=dx/d;
         dy=dy/d;
       }
       s[pair<int,int>(dx,dy)]++;
       curmax=max(curmax,s[pair<int,int>(dx,dy)]);
     }
   glomax=max(glomax,curmax+1);
 }
 cout << glomax << endl;
}

