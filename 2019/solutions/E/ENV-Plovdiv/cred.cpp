#include<iostream>
using namespace std;
int main()
{
 long n,m,a,suma,i,x,br=0;
 cin>>n>>m;
 while(n<=m)
 {
      x=n;
     while(n!=0)
     {
         x=n%10+x;
         n=n/10;
     }
     br++;
     n=x;
 }
cout<<br<<endl;
return 0;
}
