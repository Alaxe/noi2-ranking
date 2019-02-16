#include <iostream>
using namespace std;

int main()
{
int n;
int m;
int x=0;
cin>>n>>m;
while(n<=m)
{
n=n+n%10+n/10;
x++;
}
cout<<x<<endl;

 return 0;
}
