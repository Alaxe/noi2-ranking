#include <iostream>
using namespace std;
int main()
{
  long long n,brkr=0,i,a=0,b=0,nost=n;
  cin>>n;
  
  for(i=n;i>0;i=i-1) 
  {
   nost=i; 
   if(i>9){ do
            {
             a=nost%10;
            nost=nost/10;
            b=nost%10;
            nost=nost/10;   
            if(a==b) brkr++;
            } while(a>0&&b>0&&nost/10>0&&a==b);
          }
           
   if(i<10) brkr++;        
    
  }
  cout<<brkr<<endl;
  return 0; 
    
    
}