#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned char Byte;
template <int maxDig>
 class ULong
 {Byte dig[maxDig];
  int cnt;
  int cmp(const ULong<maxDig> &a) const
  {for (int i=cnt-1;i>=0;i--)
   if (dig[i]!=a.dig[i]) return (dig[i]<a.dig[i]?-1:1);
   return 0;
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
     return cmp(a)>0;
    }
    bool operator==(const ULong<maxDig> &a) const
    {if (cnt!=a.cnt) return false;
     return !cmp(a);
    }
    bool operator<(const ULong<maxDig> &a) const
    {if (cnt!=a.cnt) return cnt<a.cnt;
     return cmp(a)<0;
    }
    bool operator<=(const ULong<maxDig> &a) const
    {if (cnt!=a.cnt) return cnt<a.cnt;
     return cmp(a)<=0;
    }
    void mul10(int n)
    {if (!n) return;
     for (int i=cnt;i>=0;i--) dig[i+n]=dig[i];
     for (int i=0;i<n;i++) dig[i]=0;
     cnt+=n;
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
    void remLastDig()
    {if (cnt==1) {dig[0]=0; return;}
     for (int i=1;i<cnt;i++) dig[i-1]=dig[i];
     cnt--;
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
 {ULong<maxDig> L,R,M,t;
  if (n.getCnt()==1 && n.getDig(0)<2) return L;
  char s[maxDig];
  *s='1';
  int i;
  for (i=1;i<(n.getCnt()>>1);i++) s[i]='0';
  s[i]=0;
  L=ULong<maxDig>(s);
  R=L;
  R.mul10(2);
  do
  {
   M=5*(L+R);
   M.remLastDig();
   t=M*(M+1);
   if (t==n) return M;
   if (t<n) L=M+1;
   else R=M-1;
  }while (L<=R);
  if (R*L<=n) return R;
  return R-1;
 }
template <int maxDig>
 ULong<maxDig> sol(const ULong<maxDig> &m,const ULong<maxDig> &n)
 {return countAt1(n)-countAt1(m-1);
 }
int main()
{int const NN=128;
 ULong<NN> m,n;
 char b[NN];
 cin>>b;
 m=ULong<NN>(b);
 cin>>b;
 n=ULong<NN>(b);
 cout<<sol(m,n)<<endl;
 return 0;
}
