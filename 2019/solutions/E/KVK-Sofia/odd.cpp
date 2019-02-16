#include <iostream>

using namespace std;

int main()
{
      int a;
      int b;
      cin >> a >> b;
      int s = 0;
      int p = 0;
      int i = a;
      for (; i < b; i ++) {
                  for (int j = 1; j <= i; j++) {
                        if (i % j == 0) {
                              s++;
                        }
                  }
                  if (s % 2 == 1) {
                        p++;
                  }
                  s = 0;
   }
   cout << p;
            return 0;
}
