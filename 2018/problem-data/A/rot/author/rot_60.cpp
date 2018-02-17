#include <iostream>
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
long long power(int base,int p)
{if (!p) return 1;
 if (p&1) return base*power(base,p-1);
 long long t=power(base,p>>1);
 return t*t;
}
int digCnt(int base,long long a)
{int n=0;
 do
 {a/=base;
  n++;
 }while (a);
 return n;
}
long long bToDec(int base,const char *s)
{long long r=0;
 for (;*s;s++) r=r*base+val(*s);
 return r;
}
char *decTob(int base,long long a,char *r,int L)
{r[L--]=0;
 do
 {r[L--]=chr(a%base);
  a/=base;
 }while(a);
 return &r[L+1];
}
long long rot(int base,long long a)
{int dc=digCnt(base,a);
//cout<<"dc="<<dc<<endl;
 long long pw=power(base,dc-1);
//cout<<"pw="<<pw<<endl;
 int firstDig=a/pw;
//cout<<"firstDig="<<firstDig<<endl;
 return (a-firstDig*pw)*base+firstDig;
}
void makeInterval(int base,int digCnt,long long &from,long long &to)
{from=base+2;
 for (int i=2;i<digCnt;i++) from*=base;
 to=2*power(base,digCnt-1)-1;
}
bool solve()
{char buf[N+1];
 long long a=bToDec(b,M),f,t,m;
 int dc=digCnt(b,a);
 makeInterval(b,dc,f,t);
 while(f<=t)
 {m=((f+t)>>1);
  long long r=rot(b,m)-m;
  if (r==a){cout<<decTob(b,m,buf,N)<<endl;
            return true;
           }
  if (r<a) f=m+1;
  else t=m-1;
 }
 makeInterval(b,dc+1,f,t);
 while(f<=t)
 {m=((f+t)>>1);
  long long r=rot(b,m)-m;
  if (r==a){cout<<decTob(b,m,buf,N)<<endl;
            return true;
           }
  if (r<a) f=m+1;
  else t=m-1;
 }
 return false;
}
int main()
{cin>>b;
 for (int i=0;i<4;i++)
 {cin>>M;
  if (!solve()) cout<<"0\n";
 }
 return 0;
}
