#include <iostream>

using namespace std;

int main()
{
     int n;
     int m;
     cin >> n >> m;
     int s = 0;
     int d;
     if (n > 99 && n < 1000) {
      d = n + (n / 100 % 10) + (n / 10  %10) + n % 10;
    while ( d <  m)  {
            s++;

          d =  d + (d%1000 )+ (d / 100 % 10) + (d / 10  %10) + d % 10;
     }
     cout  << s;
     }
       if (n > 9 && n < 100) {
      d = n  + (n / 10  %10) + n % 10;
    while ( d <  m)  {
            s++;

          d =  d + (d%1000 )+ (d / 100 % 10) + (d / 10  %10) + d % 10;
     }
     cout  << s;
     }
       if (n > 0 && n < 10) {
      d = n +  n % 10;
    while ( d <  m)  {
            s++;

          d =  d + (d%1000 )+ (d / 100 % 10) + (d / 10  %10) + d % 10;
     }
     cout  << s;
     }
       if (n > 999 && n < 1001) {
      d = n + n  / 1000 + (n / 100 % 10) + (n / 10  %10) + n % 10;
    while ( d <  m)  {
            s++;

          d =  d + (d%1000 )+ (d / 100 % 10) + (d / 10  %10) + d % 10;
     }
     cout  << s;
     }

    return 0;
}
