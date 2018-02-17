#include <iostream>
using namespace std;
int main()
{
int N,L,a,b,c;
cin >>N>>L;
0<=a,b,c<=9;
if(L=3)cin>>a>>b>>c;
if(L=2)cin>>a>>b;
if(L=1)cin>>a;
cout <<a<<b<<c<<endl;
return 0;
}
