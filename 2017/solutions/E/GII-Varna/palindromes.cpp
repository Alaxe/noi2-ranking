#include<iostream>
#include<cmath>
using namespace std;
int main()
{
      int n,i,a,m=0,br=0,S,S1;
      cin>>n;
      for(i=n;i>=1;i--)
      {
      a=n-1;
      S=a*n;
      while(S/10>1){
      m=S%10;
      S1=m*pow(10,br);
      br--;
      }
      }
      if(S==S1)cout<<n<<a<<endl<<S<<endl;
      else n--;
return 0;
}
