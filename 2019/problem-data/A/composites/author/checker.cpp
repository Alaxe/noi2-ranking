#include<iostream>
#include <fstream>
#include<cstring>
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
int main(int c,char **s)
{unsigned long long n,sol;
 char buf[256],*e;
 {ifstream f(s[1]); //in-file
  if (!f){cout << "???\n";cerr<<"In-file "<<s[1]<<" not found\n";return 0;}
  f>>n;
 }
 {ifstream f(s[3]);//contestant file
  if (!f){cout<<"0\n";cerr<<"Solution not found\n";return 0;}
  f>>buf;
 }
 if (*buf=='-'){cout<<"0\n";cerr<<"Negative number in output\n";return 0;}
 if (strlen(buf)>17){cout<<"0\n";cerr<<"Output too long\n";return 0;}
 sol=strtoull(buf,&e,10);
 if (*e){cout<<"0\n";cerr<<"Incorrect output\n";return 0;}
 if (sol>=n && sol<100ULL*n && sol%6==2 && !isPrime(sol+9)){cout<<"1\n";cerr<<"Correct\n";return 0;}
 cout<<"0\n";
 cerr<<"Incorrect result\n";
 return 0;
}
