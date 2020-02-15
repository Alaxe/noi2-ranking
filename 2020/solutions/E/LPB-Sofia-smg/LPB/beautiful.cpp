#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, br1=0;
    long long br3=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
      long long a=i;
      while(a>0)
      {
          a/=10;
          br3*=10;
          br3+=1;
      }
      if(i%br3==0)
      {
          br1++;
      }
      br3=0;
    }
    cout<<br1<<endl;
    return 0;
}
