#include <iostream>
#include <vector>
#define maxU 60
using namespace std;
typedef unsigned char Byte;
ostream &operator<<(ostream &os,Byte b)
{os<<(int)b;
 return os;
}
vector<Byte>inp;
int N,U;
Byte cnt=0,alpha[maxU+1];
struct
{Byte n,k;
 unsigned long long v;
}last_n_k={0,0,0};
unsigned long long n_k(Byte n,Byte k)
{if (n<k) return 0;
 if (k>(n>>1)) k=n-k;
 if (n==last_n_k.n && k==last_n_k.k) return last_n_k.v;
 if (n==last_n_k.n-1 && k==last_n_k.k){last_n_k.v=last_n_k.v*(last_n_k.n-last_n_k.k)/last_n_k.n;
                                       last_n_k.n--;
                                       return last_n_k.v;
                                      }
 if (n==last_n_k.n-1 && k==last_n_k.k-1){last_n_k.v=last_n_k.v*last_n_k.k/last_n_k.n;
                                         last_n_k.n--;last_n_k.k--;
                                         return last_n_k.v;
                                        }
 last_n_k.n=n;last_n_k.k=k;
 unsigned long long r=1;
 for (unsigned long long i=1;i<=k;i++,n--) r=r*n/i;
 last_n_k.v=r;
 return r;
}
vector<Byte> m_th_comb(Byte n,Byte k,unsigned long long m)
{vector <Byte> r;
 unsigned long long p=n,q=k,t=n_k(n,k)-m;;
 for (Byte i=0;i<k;i++)
 {do
   p--;
  while (n_k(p,q)>t);
  r.push_back(n-p);
  t-=n_k(p,q--);
 }
 return r;
}
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
 vector<Byte> mid=m_th_comb(U,cnt,(n_k(U,cnt)+1)>>1);
 for (int i=0,j=0;i<=U;i++)
  if (alpha[i]) alpha[i]=mid[j++];
 showResult();
 return 0;
}
