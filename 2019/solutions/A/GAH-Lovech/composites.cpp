#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<unsigned long long int> P;
vector <int> vec;

int prime(int n)
{ bool is;
int i,nn;
P.insert(3);
    for (int g=3;g<=n;g=g+2){
    nn=g;
    is=1;
    for( i = 2; i < nn / 2; i++)
  {
      if(nn % i == 0)
      {
        is=0;
          break;
      }
  }
  if (is) {P.insert(nn); vec.push_back(nn);
}
}
}

int main(){
unsigned long long int x,n,p,M,i=0;
cin>>n;
if (n<1000000000)
prime(n*500);
else prime(n);
if (n%2==0)
x=n;
else x=n+1;
bool go=1,keep=1;

while (keep)
{go=1;i=0;
 while (go && i<1000 ){ //mnoj Mp
 M=vec[i]*vec[i]+x;
 if (P.count(M) != 0) //ima go
 {go=0;}
 i++;
 }
 if (go) {cout<<x<<endl; keep=0;}
 else x=x+2;
}

    return 0;
}
