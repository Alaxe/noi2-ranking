//Task: sequence
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;
 
int main()
{ int n, i, k=0;
  long long p=1;
  cin>>n;
  for (i=2; i<= n; i++) 
    {k=k+2;
     p=p+k;
    }
  cout<<p<<endl;
    return 0;
}
