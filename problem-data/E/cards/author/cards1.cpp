//Task: cards
//Author: Emil Kelevedjiev

#include<iostream>
using namespace std;

int n;
int a0,b0,a,b;

int main()
{
  cin >> n;
  cin >> a0 >> b0;
  int L=1, M=1;
  for(int i=2; i<=n; i++)
  {
    cin >> a >> b;
    int f=0;
    if(a0>=a)if(b0>=b)f=1;
    if(f==0)
    if(a0>=b)if(b0>=a)f=1;

    if(f==1)
    {
      L++;
      if(M<L) M=L;
    }
    else L=1;
    a0=a; b0=b;

  }
  cout << M << endl;
}
