#include<iostream>
using namespace std;
int main ()
{unsigned long long int n,br=0,c=0,i=1;
 cin>>n;
 
  for(i=1;i<=9;i++)      
 {
     c=i;
     while (c<=n)
     {
        br++;
        c=c*10+i;
     }
 }                                   
 cout<<br<<endl;
return 0;
}