#include <iostream>
using namespace std;
int main()
{
long long a,b,c=2,d,e=0;
cin>>a>>b;
for(int i=a;i<=b;i++)
{
c=0;
d=0;
    while(c<i)
    {
        if(i%c==0)d++;
        c++;
    }
   if(d==0||d==1)d=d+2;
   if(d%2!=0)
   {
       e++;
       cout<<i<<endl;
   }
}
cout<<e<<endl;
return 0;
 }
