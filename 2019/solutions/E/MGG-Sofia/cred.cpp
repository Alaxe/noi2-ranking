#include<iostream>
using namespace std;
int main()
{
     int n, m, br = 0;
     cin>>n>>m;
     while(n <= m)
     {
          for(int d = n; d >= 1; d /= 10)
          {
               n += d%10;
          }
          br++;
     }
     cout<<br<<endl;
     return 0;
}
