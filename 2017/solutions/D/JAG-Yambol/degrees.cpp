#include <iostream>
#include <string>
using namespace std;
int Dul (int a)
{
 long long  i;
 int m=1;
 for (i=0; i<1000000000000000000000000000000; i++)
 {
  if (a>=m && a<m*10) return i+1;
   else m=m*10;
 }
}
int main()
{
 string St;
 int br=0,i,step=1;
 cin >> St;
 for (i=0; i<St.size(); i++)
 {
  step=step*2;
  i=i+Dul(step)-1;
  if ( i>=St.size() ) break;
   else br++;
 }
 cout << br;
 return 0;
}
