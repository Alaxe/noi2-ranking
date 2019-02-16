#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,i,k,br=0,br2=0,br3=0;
     cin>>a>>b;
      for(i=a;i<=b;i++)
      {
          for(k=1;k<=i/2;k++)
          {
              br++;
          }
           br2=br;
          if(br2%2!=0)
          {
            br3++;
          }
      }

      cout<<br3<<endl;
        return 0;
}

