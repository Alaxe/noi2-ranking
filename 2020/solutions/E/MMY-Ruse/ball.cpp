#include <iostream>
using namespace std;
int main()
{
 long long x,n,a=0,b=1,c=2,i,t;
 cin >> n >> x;
 
 for(i=n;i>0;i=i-1)
 {
  if(i%2==0) { if(x==b) t=c;
              if(x==c) t=b;} 
  
  else {if(x==a) t=b;
        if(x==b) t=a;} 
 }   
 
   cout<<t<<endl;
   return 0;  
}