//Task: cred
//Author: Plamenka Hristova
#include <iostream>

using namespace std;
int main ()
{
 int n, br=0, dn,l, m;
 cin>>n>>m;
 dn=n;
 while (dn<=m)
 { l=dn;
   br++;
   while (l>0)
   {
       dn+=l%10;
       l/=10;

   }
 }
 cout<<br<<endl;
 return 0;
}
