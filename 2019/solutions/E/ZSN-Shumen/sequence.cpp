#include<iostream>
using namespace std;
int findn(int b)
{
    int br=1,a=0,K=0;
    while(K<b-1)
     {
         K++;
         for(int e=1;e<=K;e++)
         {
             br++;
             int d=e;
             a=a*10+e;
             if(d==b)return br;
         }
         for(int e=K;e>=1;e--)
         {
             br++;
             a=a*10+e;

         }


     }
     return br;
}
int main()
{
    int n;
    cin>>n;
cout<<findn(n)<<endl;

return 0;
}
