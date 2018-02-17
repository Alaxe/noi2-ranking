#include<iostream>
using namespace std;
int zCnt(unsigned long long a)//Zeros' count in a binary
{int c=0;
 while (a>1)
 {if (!(a&1)) c++;
  a>>=1;
 }
 return c;
}
unsigned long long cnt(unsigned long long s, //scan the interval
                       unsigned long long t,
                       int z)
{unsigned long long c=0;
 for (unsigned long long i=s;i<=t;i++)
    if (zCnt(i)==z) c++;
 return c;
}
int main()
{unsigned long long s,t;
 int z;
 cin>>s>>t>>z;
 cout<<cnt(s,t,z)<<endl;
 return 0;
}
