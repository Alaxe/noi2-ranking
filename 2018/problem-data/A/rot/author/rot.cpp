#include <iostream>
using namespace std;
int const N=10000;
char A[N+1],M[N+1];
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
void solve()
{if (!check()){cout<<"0\n"; return;}
 int i=N-1,borrow=0,t,f=1;
 A[i]=0;
 for (int j=len-1;j>=0;j--)
 {f=f-val(M[j])-borrow;
  if (f<0){f+=b;borrow=1;}
  else borrow=0;
  A[--i]=chr(f);
 }
 if (f!=1) A[--i]='1';
 cout<<&A[i]<<endl;
}
int main()
{cin>>b;
 for (int i=0;i<4;i++)
 {cin>>M;
  solve();
 }
 return 0;
}
