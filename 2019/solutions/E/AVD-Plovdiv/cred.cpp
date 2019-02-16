#include<iostream>
using namespace std;
int main()
{
    int n,m,a,a1,k,i,br;
     cin>>n>>m;
      if(n<100 && n>9)
        {
            a=n/10;
            a1=n%10;
            while(n<m)
            {
                i=a+a1;
                n=n+i;
                n=n+2*i;
                 br++;
            }

        }
         cout<<br<<endl;
      return 0;
}
