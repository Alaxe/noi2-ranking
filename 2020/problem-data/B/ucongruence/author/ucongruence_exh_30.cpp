#include <iostream>
#include <vector>
#define maxU 60
using namespace std;
typedef unsigned char Byte;
ostream &operator<<(ostream &os,Byte b)
{os<<(int)b;
 return os;
}
bool nextComb(int n,vector<Byte> &a)
{int k=a.size();
 for (int i=k-1;i>=0;i--)
  if (a[i]<n-k+i+1)
  {a[i]++;
   for (i++;i<k;i++) a[i]=a[i-1]+1;
   return true;
  }
 return false;
}
bool prevComb(int n,vector<Byte> &a)
{int k=a.size();
 int i=k-1;
 while (i>0 && a[i]==a[i-1]+1) i--;
 if (!i && a[i]==1) return false;
 a[i]--;
 for (int j=k-1;j>i;j--) a[j]=n--;
 return true;
}
vector<Byte> init(int k)
{vector<Byte> a;
 for (int i=0;i<k;i++) a.push_back(i+1);
 return a;
}
vector<Byte> revInit(int n,int k)
{vector<Byte> a;
 for (int i=n-k+1;i<=n;i++) a.push_back(i);
 return a;
}
vector<Byte>inp;
int N,U;
Byte cnt=0,alpha[maxU+1];
void getData()
{cin>>N>>U;
 for (int i=0;i<=U;i++) alpha[i]=0;
 inp.resize(N);
 int a;
 for (int i=0;i<N;i++)
 {cin>>a;
  inp[i]=a;
  if (!alpha[a]) {alpha[a]=1;cnt++;}
 }
}
void showResult()
{for (int i=0;i<inp.size()-1;i++) cout<<alpha[inp[i]]<<' ';
 cout<<alpha[inp[inp.size()-1]]<<'\n';
}
int main()
{ios::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 getData();
 vector<Byte> inc=init(cnt),dec=revInit(U,cnt);
 do
 {if (inc==dec) break;
  prevComb(U,dec);
  if (inc==dec) break;
  nextComb(U,inc);
 }while(true);
 for (int i=0,j=0;i<=U;i++)
  if (alpha[i]) alpha[i]=inc[j++];
 showResult();
 return 0;
}
