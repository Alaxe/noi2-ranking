#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
  unsigned long long n,ob,n2;
  cin>>n;
  ob=n;
for(int i=n;i>0;i--)
{
    n=n-1;
ob=ob+n;
}
cout<<ob<<endl;
   return 0;
}