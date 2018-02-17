//Task: palindromes
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;
                
int main()
{ int n,i,j,a,b,maxx=0,k,l;
  cin>>n;
  for (i=1;i<=n-1;i++)
      for (j=i;j<=n-1;j++)
         {a=i*j; 
          b=0;
          while (a>0)
             {b=b*10+a%10;
              a=a/10;
             }
          if (b==i*j && i*j>maxx) 
             {maxx=i*j;
              k=i;
              l=j;
             }  
          }   
  cout<<k<<" "<<l<<endl<<maxx<<endl;         
}  


