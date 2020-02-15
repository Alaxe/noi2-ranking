//Task: ball
//Author: Zornica Dzhenkova
#include <iostream>
using namespace std;
int main()
{
    long long int n,x,k;
    cin>>n>>x;
    for(long long int i=n;i>0;i--)
    { if(i%2)
      {
        if(x==0)x=1;
        else if(x==1)x=0;
      }
      else
      {
        if(x==2)x=1;
        else if(x==1)x=2;
      }
    }
    cout << x << endl;
}
