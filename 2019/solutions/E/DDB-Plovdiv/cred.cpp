#include<iostream>
using namespace std;
int main ()
{
long long min1,max1,br=0;
cin>>min1>>max1;
for (int i=min1;min1<=max1;)
{
min1=min1+(min1/100000)+(min1/10000)+(min1/1000)+(min1/100)+(min1/10);
if (min1<max1) br++;
}
cout<<br<<endl;
return 0;
}
