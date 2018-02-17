#include <iostream>
#include <cstring>
using namespace std;
int const N=10000;
char M[N+1];
int b,len;
int val(char c)
{if (c>='0' && c<='9') return c-'0';
 return c-'A'+10;
}
char chr(int v)
{if (v<10) return '0'+v;
 return 'A'+v-10;
}
bool check()
{int r=0;
 len=0;
 for (;M[len];len++)
    r=(b*r+val(M[len]))%(b-1);
 return !r;
}
char *div(int d,char *r,int *j)
{int i=0;
 int f=val(M[i]);
 *j=0;
 if (f<d) f=b*f+val(M[++i]);
 r[(*j)++]=chr(f/d);
 f%=d;
 for (i++;M[i];i++)
 {f=b*f+val(M[i]);
  r[(*j)++]=chr(f/d);
  f%=d;
 }
 r[*j]=0;
 return r;
}
char *makeSpec(int base,int m,char *r)
{for (int i=0;i<m-1;i++) r[i]=chr(base-2);
 r[m-1]=chr(base-1);
 r[m]=0;
 return r;
}
char *make120_0(int m,char *r)
{int i=0;
 r[i++]='1';r[i++]='2';
 for(;i<m+2;i++) r[i]='0';
 r[i]=0;
 return r;
}
char *add(int base,const char *a,int La,const char *b,int Lb,char *c,int *Lc)
{int carry=0,L;
 *Lc=(La>Lb)?La:Lb;
 c[1+*Lc]=0;
 for (La--,Lb--,L=*Lc;La>=0 || Lb>=0;La--,Lb--,L--)
 {int d=carry;
  if (La>=0) d+=val(a[La]);
  if (Lb>=0) d+=val(b[Lb]);
  if (d>=base){d-=base;carry=1;}
  else carry=0;
  c[L]=chr(d);
 }
 if (carry){c[L--]='1';(*Lc)++;}
 return 1+&c[L];
}
char *sub(int base,const char *a,int La,const char *b,int Lb,char *c,int *Lc)
{int borrow=0;
 *Lc=La;
 c[La]=0;
 for (La--,Lb--;La>=0;La--,Lb--)
 {int d=val(a[La])-borrow;
  if (Lb>=0) d-=val(b[Lb]);
  if (d<0){d+=base;borrow=1;}
  else borrow=0;
  c[La]=chr(d);
 }
 La=0;
 while (La<*Lc-1 && a[La]=='0') La++;
 *Lc-=La;
 return &c[La];
}
void solve()
{char T[N],p[N],q[N],t[N],*pT,*pq,*pt;
 int m,Lt,Lq;
 if (!check()){cout<<"0\n"; return;}
 pT=div(b-1,T,&m);
 makeSpec(b,m,p);
 if (strcmp(pT,p)>=0)
 {
  make120_0(m,q);
  pt=add(b,q,m+2,T,m,t,&Lt);
  pq=sub(b,pt,Lt,p,m,q,&Lq);
 }
 else
 {p[m-2]=chr(b-1);p[m-1]=0;
  make120_0(m-1,q);
  pt=add(b,q,m+1,T,m,t,&Lt);
  pq=sub(b,pt,Lt,p,m-1,q,&Lq);
 }
 cout<<pq<<endl;
}
int main()
{cin>>b;
 for (int i=0;i<4;i++)
 {cin>>M;
  solve();
 }
 return 0;
}
