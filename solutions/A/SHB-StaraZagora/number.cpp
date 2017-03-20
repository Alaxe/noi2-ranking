#include <iostream>
#include <math.h>

using namespace std;

int main()
{


long long n,m;
cin>>n>>m;
n=sqrt (n) + 0.5;
m= sqrt (m+1) + 0.5;

cout<<m-n;

return 0;


}