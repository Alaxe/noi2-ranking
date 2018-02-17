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
int zCnt(unsigned long long a,unsigned long long m)//Zeros' count in a binary
                                                   //using ones' count
{int c=0;
 a^=m;
 while (a)
 {c++;
  a&=(a-1);
 }
 return c;
}
void getLimits(int len,int z,unsigned long long s,unsigned long long t,
               unsigned long long *from,unsigned long long *to)
{unsigned long long m=((1ULL)<<len)-1,zm=((1ULL)<<z)-1;
 *to=(m^zm);
 zm<<=(len-z-1);
 *from=(m^zm);
 if (*from<s) *from=s;
 if (*to>t) *to=t;
}
//scan [s,t] using binary operations, adjusting start and end for each bit length
unsigned long long cnt(unsigned long long s,unsigned long long t, int z)
{unsigned long long from,to,m,c=0;
 int sl=binDigCnt(s),tl=binDigCnt(t);
 for (int L=sl;L<=tl;L++)
 {getLimits(L,z,s,t,&from,&to);
  m=((1ULL)<<L)-1;
  for (unsigned long long i=from;i<=to;i++)
   if (zCnt(i,m)==z)c++;
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
