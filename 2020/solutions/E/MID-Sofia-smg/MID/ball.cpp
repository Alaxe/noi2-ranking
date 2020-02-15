#include <iostream>
using namespace std;

int main()
{
long long n;
int x;
cin>>n>>x;
n=n%6;
if (((n==0 || n==5) && x==0) || (x==1 &&(n==1 || n==4)) || (x==2 &&(n==2 || n==3))) cout<<"0"<<endl;
else
{
if (((n==1 || n==2) && x==0) || (x==1 && (n==0 || n==3)) || (x==2 || (n==4 || n==5))) cout<<"1"<<endl;
else cout<<"2"<<endl;
}
return 0;
}
