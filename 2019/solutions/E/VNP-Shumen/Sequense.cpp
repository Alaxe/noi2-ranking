#include<iostream>
#include<cmath>
using namespace std;
int main()
{
     int n,mp=1,p,r=1,nn;
     cin>>n;
     for ( nn=1;nn=n;nn++)
     {
         if (n==nn)
         {
             p=mp-r+1;
         }
         else
         {
             mp=mp+mp*2;
             r++;
         }
     }
     p=mp-r+1;
     cout<<p<<endl;



return 0;
}
