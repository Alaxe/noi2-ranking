#include <iostream>
#include <iomanip>
#include <math.h>
#include<bits/stdc++.h>


using namespace std;
bool isPrime (int a)
{
  if (a == 1)
  {
    return false;
  }
  int i = 2;
  while (i*i <= a)
  {
      if (a % i == 0)
      {
          return false;
      }
      i += 1;
  }
  return true;
}

int main ()
{
    int n;
    cin>>n;

    for (int i=2; i<INT_MAX; i++)
        for (int j=2; j<i; j++)
        {
            if (i % j == 0)
                break;

            else if (i == j+1)
            for(int y=n; y<=INT_MAX; y++)
            {
              if(y%2==1) y++;

              for(int z=pow(i,2)+y; z<=INT_MAX; z=pow(i,2)+y)
              {
                    if(isPrime(z)== false) {
                            break;}
                            else{
                                cout<<y<<endl; break;
                            }

                    }
              }


            }


    return 0;
}

