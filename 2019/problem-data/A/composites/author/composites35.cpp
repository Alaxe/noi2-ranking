#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(unsigned long long a)
{unsigned long long d,p;
 if (a==1) return false;
 if (a==2) return true;
 if (!(a&1)) return false;
 d=(unsigned long long)round(sqrt(a));
 p=3;
 while (p<=d)
 {if (!(a%p)) return false;
  p+=2;
 }
 return true;
}
unsigned long long getX(unsigned long long lo)
{unsigned long long p,t;
 if (lo&1) lo++;
 for (;true;lo+=2)
 {if (isPrime(9+lo))continue;
  for (p=1;p<=200;p++)
  {t=6*p-1;
   if (isPrime(t) && isPrime(t*t+lo)) break;
   t=6*p+1;
   if (isPrime(t) && isPrime(t*t+lo)) break;
  }
  if (p>200) return lo;
 }
}
int main()
{unsigned long long n,x;
 cin>>n;
 x=getX(n);
 cout<<x<<endl;
 return 0;
}
