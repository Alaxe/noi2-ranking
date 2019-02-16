//Task: sequence-2
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;
 
int main()
{ int n, l, k;
  long long m;
  cin>>n>>k;
  m=n;
  m=m*(n-1)+1;
  if (k>1) 
    {l=k / 2;
     m=n+l;
     m=m*(m-1)+1;
     if (k % 2==0)  m=m-l;
     else m=m+l;
    }
  cout<<m<<endl;
    return 0;
}
 
  
  
