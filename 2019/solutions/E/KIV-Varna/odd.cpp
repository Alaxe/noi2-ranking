#include<iostream>
using namespace std;
int main()
{  long long int a,b,i,j,brd=0,br=0;
   cin>>a>>b;
   for(i=a; i<=b; i++)
   {  for(j=1; j<=i; j++)
      {  if(i%j==0)brd++;
      }
      if(brd%2==1)br++;
      brd=0;
   }
   cout<<br<<endl;
   return 0;
}
