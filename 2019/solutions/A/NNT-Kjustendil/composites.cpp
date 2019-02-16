#include <iostream>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;
int main() {

    int n = 0;
    cin>>n;

    for(int i = 0; i <= INT_MAX; i++)
    {
        int counter = 0;
        if(isPrime(i)){

        }

    }
}
bool isPrime (int a)
{
  if (n == 1)
  {
    return false;
  }
  int i = 2;
  while (i*i <= n)
  {
      if (n % i == 0)
      {
          return false;
      }
      i += 1;
  }
  return true;
}
