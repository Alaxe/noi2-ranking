#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string s;
int sz;
string new1,new2;
struct el
{
    string s2;
    int pos;
};
el c[15000000];
void prisv()
{
  for(int i=0;i<sz;i++)
  {
    c[i].s2=s[i];
    c[i].pos=i;
  }
}
int cmp(el x,el y)
{
    if(x.s2<y.s2)return true;
    if(x.s2>y.s2)return false;
}
void solve()
{
    new1[c[0].pos]='A';int j=0;
    for(int i=1;i<sz;i++)
    {
      if(c[i].s2!=c[i-1].s2)
      {
          j++;
      }
      new1[c[i].pos]=(char)('A'+j);
    }
   new2[c[sz-1].pos]='Z';int h=0;
   for(int i=sz-2;i>=0;i--)
   {
       if(c[i].s2!=c[i+1].s2)
      {
          h++;
      }
      new2[c[i].pos]=(char)('Z'-h);
   }
}
int main()
{
    cin>>s;
    sz=s.size();
    prisv();
    sort(c,c+sz,cmp);
    solve();
    for(int i=0;i<sz;i++)
    {
      cout<<new1[i];
    }
    cout<<endl;
    for(int i=0;i<sz;i++)
    {
      cout<<new2[i];
    }
    cout<<endl;
    return 0;
}
