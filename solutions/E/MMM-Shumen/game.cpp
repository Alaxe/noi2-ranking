#include <iostream>
using namespace std;
int main ()
{
    
    int m,k,n;
    cin>>m>>k;
    for(int i;i<k;i++)
    {
        cin>>n;
    }
    int sum=0;
    if(k%2==0)sum+=k;
    if(sum>k||sum>200)cout<<sum<<endl;
  



return 0;
}