#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <cstring>
using namespace std;
int main()
{
   int a,b;
   cin>>a>>b;
   int n;
   cin>>n;
   int br=1;
   int a2,b2;
   for(int i=1;i<n;i++)
   {
       cin>>a2>>b2;
       if(a2<=a&&b2<=b)br++;
   }
   cout<<br<<endl;
    return 0;
}
