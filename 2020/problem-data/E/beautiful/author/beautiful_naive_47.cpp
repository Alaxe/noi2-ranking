//Task: beautiful_naive
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;
 
    int main()
{long long int n; 
 cin >> n; 
 int ans = 0; 
 for (int d = 1; d <= n; d++) 
   {bool f=true;
    int j=d;
    int k=j%10;
    j=j/10;
    while (j>0 && f) 
       {int m=j%10; 
        if (k!=m) f=false;
        j=j/10;
        k=m;
       } 
   if (f) ans++; 
   } 
 cout << ans<<endl;
 return 0;
}
