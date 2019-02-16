#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(unsigned long long a)
{unsigned long long d,p;
 switch (a)
 {case 1:return false;
  case 2:return true;
  case 3:return true;
 }
 if (!(a&1)) return false;
 if (!(a%3)) return false;
 d=(unsigned long long)round(sqrt(a));
 p=5;
 while (p<=d)
 {if (!(a%p)) return false;
  if (!(a%(p+2))) return false;
  p+=6;
 }
 return true;
}

int main()
{unsigned long long x,t;
 cin>>x;
 t=x-(x%6)+2;
 if (t<x) t+=6;
 x=t;
 while (isPrime(x+9)) x+=6;
 cout<<x<<endl;
 return 0;
}

