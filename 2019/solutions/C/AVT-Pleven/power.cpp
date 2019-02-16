# include<iostream>
using namespace std;
long long  a,k,n,B,exN=1,c=1;
int main()
{
     cin>>n>>k;
     for(int i=1; i<=n; i++)
     {
         cin>>a;
         exN=exN*a;
     }
     if(k==1)
     {
         cout<<exN;
         return 0;
     }
     if(exN%2==0)
     {
         c=c*2;
     }
     if(exN%3==0)
     {
         c=c*3;
     }
     if(exN%5==0)
     {
         c=c*5;
     }if(exN%7==0)
     {
         c=c*7;
     }
     if(exN%11==0)
     {
         c=c*11;
     }
     if(exN%13==0)
     {
         c=c*13;
     }
     if(exN%17==0)
     {
         c=c*17;
     }if(exN%19==0)
     {
         c=c*19;
     }
     if(exN%23==0)
     {
         c=c*23;
     }
     if(exN%29==0)
     {
         c=c*29;
     }if(exN%31==0)
     {
         c=c*31;
     }
     if(exN%37==0)
     {
         c=c*37;
     }
     if(exN%41==0)
     {
         c=c*41;
     }
     cout<<c;
    return 0;
}
