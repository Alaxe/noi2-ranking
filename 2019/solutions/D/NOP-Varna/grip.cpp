#include <iostream>
#define endl '\n'
using namespace std;
int dnimax(int m,int g)
{
    if(m==4 || m==6 || m==9 || m==11) return 30;
    if(m==2 && (g%4==0 && (g%100!=0 || g%400==0))) return 29;
    if(m==2) return 28;
    return 31;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

   int d,m,g,uch,densedm,brdni=0,dni=0,u=0;
   char c;
   cin>>d>>c>>m>>c>>g>>uch;

   u=uch;
   if(g==2020) brdni+=365;

  for(int i=1;i<m;i++)
  {
    brdni+=dnimax(i,g);
  }

  brdni=d-1+brdni;

  if(d==1 && m==1 && g==2020) brdni=365;

  densedm=(brdni%7+2)%7;
  if(densedm==0) densedm=7;
  if(u==1)
  {
      densedm++;d++;
      if(densedm==6) d+=2;
      if(densedm==7) d+=1;
      if(d>dnimax(m,g))
          {
              m++;
              d=1;
              if(m>12)
              {
                  g++;
                  m=1;
              }
          }

      cout<<d/10<<d%10<<"."<<m/10<<m%10<<"."<<g<<endl;
      return 0;
  }
  if(densedm<=5) uch--;

      while(densedm<7)
      {
          densedm++;
          if(densedm<=5) uch--;
          d++;
          if(d>dnimax(m,g))
          {
              m++;
              d=1;
              if(m>12)
              {
                  g++;
                  m=1;
              }
          }
      }
      int d2=d;
      while(uch>=5)
      {
          uch-=5;
          d+=7;
          if(d>dnimax(m,g))
          {
              d=d-dnimax(m,g);
              m++;
              if(m>12)
              {
                  g++;
                  m=1;
              }
          }
    }

      if(densedm==0) densedm=7;

      if(densedm==6){d+=2;densedm=1;}
      else if(densedm==7){d+=1;densedm=1;}

      d+=uch;

      densedm+=uch;
      densedm%=7;
      if(densedm==0) densedm=7;

      if(densedm==6)d+=2;
      else if(densedm==7)d+=1;


          if(d>dnimax(m,g))
          {
              m++;
              d=1;
              if(m>12)
              {
                  g++;
                  m=1;
              }
          }

  cout<<d/10<<d%10<<"."<<m/10<<m%10<<"."<<g<<endl;

}
