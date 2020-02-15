#include <iostream>
#include <cstring>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
string niz, niz2;
cin >> niz;
int j=0;
for(int i=0; i<niz.size(); ++i)
{
   if(niz[i]!='(' && niz[i]!=')')
   {
       niz2.push_back(niz[i]);
   }
}
cout << niz2;


return 0;
}
