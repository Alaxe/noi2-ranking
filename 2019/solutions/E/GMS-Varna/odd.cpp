#include <iostream>
using namespace std;
int main()
{
int a,b,a1;
cin>>a>>b;
a1=b-a+1;
cout<<a1<<endl;
while(a<=b)
{
a++;
if(a%2!=0) cout<<a<<endl;
}
return 0;
}
