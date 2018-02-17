#include<iostream>
#include<algorithm>
using namespace std;

int n;
struct P {int a,b;};
P p[722];

bool cmp(P p1, P p2)
{
  return p1.a < p2.a;
}

int main()
{
  n=0;
  while(cin >> p[n].a >> p[n].b) n++;
  sort(p,p+n,cmp);

  int c=p[0].a;
  int s=p[0].b;

  for(int i=1;i<n;i++)
  {
    s = s-(p[i].a-c);
    if(s<0)s=0;
    c=p[i].a;
    s = s + p[i].b;
  }
  cout << s << endl;
}

