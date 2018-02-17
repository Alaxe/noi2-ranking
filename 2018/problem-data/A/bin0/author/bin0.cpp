#include<iostream>
using namespace std;
int binDigCnt(unsigned long long a)//Binary digits' count
{int c=0;
 do
 {a>>=1;
  c++;
 }while (a);
 return c;
}
int zCnt(unsigned long long a)//Zeros' count in a binary
{int c=0;
 while (a>1)
 {if (!(a&1)) c++;
  a>>=1;
 }
 return c;
}
unsigned long long n_k(int n,int k)//Combinations' count
{if (k>n) return 0;
 unsigned long long s=1;
 for (int i=0;i<k;i++) s=(s*(n-i))/(i+1);
 return s;
}
unsigned long long combNo(int n,int k,const char *a)
//combination alphabetic number (one based)
{unsigned long long s=1;
 for (int i=1;i<=k;i++)
  for (int j=a[i-1]+1;j<=a[i]-1;j++)
   s+=n_k(n-j,k-i);
 return s;
}
int makeFirstComb(int zCount,unsigned long long a,char *r)//Next combination, starting at a
//return 0:pattern is a; 1:pattern after a; -1 - no pattern after a
{int i=1,j=1,c=binDigCnt(a)-1,z=0;
 unsigned long long m;
 *r=0;
 if (zCount>c) return -1;//Digits not enough
 if (!zCount)//No zeros case
 {m=(1ULL<<(c+1))-1;
  return (a==m)?0:1;
 }
 else
 {m=(1ULL << (c-1));
  while (m)
  {if (!(m & a)) r[++z]=i;
   i++;
   m>>=1;
  }
 }
 //make zeros' places array
 if (z>=zCount) return (zCnt(a)==zCount)?0:1;//is a or after a
 while (z>=1 && c-r[z]<zCount-z+1) z--;
 if (z<1) return -1;//no pattern after a
 //create first pattern after a
 r[z]++;
 for (z++;z<=zCount;z++) r[z]=r[z-1]+1;
 return 1;//pattern after a
}
unsigned long long cnt(unsigned long long s,unsigned long long t, int z)
//solve the problem
{unsigned long long c=0,F1,F2;
 char d[64];
 int sc=binDigCnt(s)-1,tc=binDigCnt(t)-1;
 if (sc==tc) //equal digits' case
 {switch (makeFirstComb(z,s,d))
  {case -1:return 0;
   case 0:
   case 1:F1=combNo(sc,z,d);
  }
  if (!F1) return 0;//no elements after a
  switch (makeFirstComb(z,t,d))
  {case -1:{F2=n_k(tc,z);break;}
   case 0:{F2=combNo(tc,z,d);break;}
   case 1:F2=combNo(tc,z,d)-1;
  }
  return F2-F1+1;
 }
 //common case
 for (int i=sc+1;i<=tc-1;i++) c+=n_k(i,z);
 if (makeFirstComb(z,s,d)>=0) c+=(n_k(sc,z)-combNo(sc,z,d)+1);
 switch(makeFirstComb(z,t,d))
 {case -1:{c+=n_k(tc,z);break;}
  case 1: c--;
  case 0: c+=combNo(tc,z,d);
 }
 return c;
}
int main()
{unsigned long long s,t;
 int z;
 cin>>s>>t>>z;
 cout<<cnt(s,t,z)<<endl;
 return 0;
}
