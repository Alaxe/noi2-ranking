#include <iostream>

using namespace std;

int main()
{
      int n;
      cin >> n;
      int h = 1;
      int s = 0;
      int i;
      for ( i = 1; i < n; i++ )  {
            s = s + h;
            h = h + 2;
      }
      s = s + n;
      cout << s;
    return 0;
}
