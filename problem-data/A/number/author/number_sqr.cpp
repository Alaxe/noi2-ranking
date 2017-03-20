#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned char Byte;
template <int maxDig>
 class ULong
 {Byte dig[maxDig];
  int cnt;
  void addTwoDig(const ULong<maxDig> &a,int &ind)
  {*this=*this*10;
   dig[0]=a.dig[ind--];
   if (!(ind&1))
   {*this=*this*10;
    dig[0]=a.dig[ind--];
   }
  }
  int nextDig(ULong<maxDig> &a) const
  {int d=9;
   ULong<maxDig> t1=10*a,t;
   t=t1*2;
   for (d=9;d>=0;d--)
   {t.dig[0]=d;
    if (!(t*d>*this)) break;
   }
   t=*this-(t*d);
   a=t;
   return d;
  }
  void mul10(int n)
  {if (!n) return;
   for (int i=cnt;i>=0;i--) dig[i+n]=dig[i];
   for (int i=0;i<n;i++) dig[i]=0;
   cnt+=n;
  }
 public:
  Byte getDig(int n) const
  {return dig[n];
  }
  int getCnt() const
  {return cnt;
  }
  ULong (unsigned long long a=0)
  {cnt=0;
   do
   {dig[cnt++]=a%10;
    a/=10;
   }while (a);
  }
  ULong (const char *s)
  {int L=strlen(s)-1;
   if (L<0) *this=ULong();
   else
   {cnt=0;
    while (L>=0) dig[cnt++]=s[L--]-'0';
   }
  }
  bool operator>(const ULong<maxDig> &a) const
  {if (cnt!=a.cnt) return cnt>a.cnt;
   for (int i=cnt-1;i>=0;i--)
    if (dig[i]!=a.dig[i]) return dig[i]>a.dig[i];
   return false;
  }
  ULong operator + (const ULong &a) const
  {ULong r;
   Byte c=0;
   int i;
   for (i=0;i<cnt || i<a.cnt;i++)
   {r.dig[i]=c;
    if (i<cnt) r.dig[i]+=dig[i];
    if (i<a.cnt) r.dig[i]+=a.dig[i];
    if (r.dig[i]>=10){r.dig[i]-=10;c=1;}
    else c=0;
   }
   if (c) r.dig[i++]=1;
   r.cnt=i;
   return r;
  }
  ULong operator-(const ULong<maxDig> &a) const
  {if (a>*this) throw "Negative result";
   int b=0,t;
   ULong<maxDig> r;
   for (int i=0;i<cnt;i++)
   {t=dig[i]-b;
    if (i<a.cnt) t-=a.dig[i];
    if (t<0) {t+=10;b=1;}
    else b=0;
    r.dig[i]=t;
   }
   r.cnt=cnt;
   while (r.cnt>1 && !r.dig[r.cnt-1]) r.cnt--;
   return r;
  }
  ULong operator*(int a) const
  {Byte c=0;
   int t;
   ULong<maxDig> r;
   if (!a) return r;
   if (a==1) return *this;
   for (int i=0;i<cnt;i++)
   {t=a*dig[i]+c;
    r.dig[i]=t%10;
    c=t/10;
   }
   r.cnt=cnt;
   if (c) r.dig[r.cnt++]=c;
   return r;
  }
  ULong operator*(const ULong &a) const
  {ULong r,q;
   Byte c=0;
   int i;
   for (i=0;i<cnt;i++)
   {ULong t=a*dig[i];
    t.mul10(i);
    q=r+t;
    r=q;
   }
   return r;
  }
  ULong sqrt() const
  {ULong<maxDig> r,t,q;
   int ind=cnt-1;
   while (ind>=0)
   {q.addTwoDig(*this,ind);
    t=r;
    int d=q.nextDig(t);
    r=10*r;
    r.dig[0]=d;
    q=t;
   }
   return r;
  }
 };

ostream &operator<<(ostream &os,Byte b)
{os<<(int)b;
 return os;
}
template <int maxDig>
 ULong<maxDig> operator*(int a,const ULong<maxDig> &b)
 {return b*a;
 }
template <int maxDig>
 ostream &operator<<(ostream &os,const ULong<maxDig> &u)
 {for (int i=u.getCnt()-1;i>=0;i--) os<<u.getDig(i);
  return os;
 }
template <int maxDig>
 ULong<maxDig> countAt1(const ULong<maxDig> &n)
 {ULong<maxDig> t;
  if ((ULong<maxDig>)2>n) return t;
  t=n.sqrt();
  ULong<maxDig> q=t*(t+1);
  if (q>n) t=t-1;
  return t;
 }
template <int maxDig>
 ULong<maxDig> sol(const ULong<maxDig> &m,const ULong<maxDig> &n)
 {return countAt1(n)-countAt1(m-1);
 }
int main()
{int const NN=128;
 ULong<128> m,n;
 char b[NN];
 cin>>b;
 m=ULong<NN>(b);
 cin>>b;
 n=ULong<NN>(b);
 cout<<sol(m,n)<<endl;
 return 0;
}
