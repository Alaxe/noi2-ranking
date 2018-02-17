#include<iostream>
using namespace std;
int main ()
{
    char a,b,c,ch;
   long long N,a1,b1,c1,d;
   cin>>N;
   if((N<=a)&&(N<=b)) cout<<"Error!Incorrect input."<<endl;
   if(N<=1) cout<<"Error!Incorrect input."<<endl;
   a*b==c;
   if (N==1*a1+10*b1)
   {
     a1=N/10;
     b1=N%10;
   } cout<<<<endl;
    if (N==1*a1+10*b1+100*c1)
   {
     a1=N/100;
     b1=N/10%10;
     c1=N%10;
   } cout<<<<endl;
     if (N==1*a1+10*b1+100*c1+1000*d)
   {
     a1=N/1000;
     b1=N/100%10;
     c1=N/10%10;
     d=N%10;
   } cout<<<<endl;
   if (a>b) cout<<b<<a<<endl;
            cout<<b*a<<endl;
   if (a<b) cout<<a<<b<<endl;
            cout<<a*b<<endl;


}
