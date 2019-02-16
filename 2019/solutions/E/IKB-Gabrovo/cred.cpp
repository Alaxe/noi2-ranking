#include <iostream>
using namespace std;
int main()
{
int n,d,m,a=1,b;
cin>>n>>m;
d=n+(n/1000)+((n/100)%10)+((n/10)%10)+(n%10);
while(d<=m)
{
d=d+(d/1000)+((d/100)%10)+((d/10)%10)+(d%10);
if(d<m)a++;
}
cout<<a+1<<endl;
return 0;
 }
