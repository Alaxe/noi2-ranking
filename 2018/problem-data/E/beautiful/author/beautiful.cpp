//Task: beautiful
//Author: Kinka Kirilowa-Lupanowa

#include <iostream>
using namespace std;

int main()
{ int n, k;
  long long p;
  cin >> n >> k;
  if (n==1 && k==10) cout<<"NO"<<endl;
  else 
      {p=1; 
       while (n>1) 
          {n=n-1;
           p=p*10;
          }
       while (p % k !=0)  p=p+1;
       cout<<p<<endl;
      }
return 0;
}
 
 
