//Task: degrees
//Author: Kinka Kirilova-Lupanova
#include <iostream>

using namespace std;
int main()
{ int n, i, ka, p, a[65000];
  char c;
  n=0; ka=0; a[0]=1;
  while (cin>>c) 
      {n=n+1;
       p=0;
       for (i=0;i<=ka; i++) 
           {p=p+a[i]*2; a[i]=p % 10; p=p / 10;
           }
      if (p>0) {ka=ka+1; a[ka]=p;} 
      for (i=0; i<ka;i++)  cin>>c;
     }
  cout<<n<<endl;
return 0;
}                       

