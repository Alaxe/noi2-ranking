#include <iostream>
using namespace std;
int main()
{

ios::sync_with_stdio(false);
cin.tie(nullptr);

long long n,i;

cin>>n;

 for(i=n;i<=n+1000;i++)
 {
   if(i%2==0 && i%3==2 && i%5==1)
   {
    cout<<i<<"\n";
    return 0;
   }
 }

return 0;
}
