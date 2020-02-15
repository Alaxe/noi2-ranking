#include <iostream>
using namespace std;

int main()
{
long long N;
int a=0,e=9;
cin>>N;
if(N/10==0)cout<<N<<endl;
else
{
for(int b=10;b<=N;b++)
{
if (b%11==0 || b%111==0 || b%11111==0 || b%1111111==0 || b%11111111111==0 || b%1111111111111==0 || b%1111111111111111==0) e++;
}
cout<<e<<endl;
}
return 0;
}
