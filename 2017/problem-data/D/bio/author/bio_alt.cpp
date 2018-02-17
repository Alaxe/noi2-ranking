#include<iostream>
using namespace std;

int dm[]={31,28,31,30,31,30,31,31,30,31,30,31};
int cyc[3]={23,28,33};
int m[3];
bool b[3];

int read()
{
  string s;
  cin >> s;
  int i=0;
  int v1=0;
  while(s[i] !='/')
  {
    int w=(int)(s[i]-'0');
    v1 = 10*v1+w;
    i++;
  }
  i++;
  int v2=0;
  while(i<s.size())
  {
    int w=(int)(s[i]-'0');
    v2 = 10*v2+w;
    i++;
  }

  int r=0;
  for(int i=0;i<v2-1;i++) r += dm[i];
  r += v1;
  return r;
}
int main()
{
  for(int i=0;i<3;i++) m[i]=read();
  int d=read();
  int t=1;
  while(1)
  {
    t++;
    for(int i=0;i<3;i++) b[i]=(m[i]-t)%cyc[i];
    if((b[0]==0)&&(b[1]==0)&&(b[2]==0))
      if(t!=d) {cout << t-d << endl; return 0;}
  }
}
