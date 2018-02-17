#include <iostream>
using namespace std;
int main()
{
  long long int n,k,h=1;
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
   {
     h*=10;
   }
    if(h%k==0)cout<<h<<endl;
     else
    {
        while(h%k!=0)
        {
             h+=n;
        }
        cout<<h<<endl;
    }

    return 0;
}
