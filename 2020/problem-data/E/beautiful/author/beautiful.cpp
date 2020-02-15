//Task: beautiful
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;
 
    int main()
{unsigned long long int n; 
 cin >> n; 
 int ans = 0; 
 for (int d = 1; d <= 9; d++) 
   {unsigned long long int cur = d; 
    while (cur <= n) 
       {ans++; 
        cur = cur * 10 + d; 
       } 
   } 
 cout << ans<<endl;
 return 0;
}
