#include <iostream>
using namespace std;
int main()
{
int n,x,a,b,c,d,e;
cout<<"Molia vuvedete broia na hodovetre na Pesho:";
cin>>n;
cout<<"Molia vuvedete krainia nomere na cashata:";
cin>>x;
a=x+1;
while(a>2)
{a=a-2;}
b=x+2;
while(b>2)
{b=b-2;}
c=x+3;
while(c>2)
{c=c-2;}
d=x+4;
while(d>2)
{d=d-2;}
e=x+5;
while(e>2)
{e=e-2;}
if(n%6==0) cout<<"Topceto e v "<<x<<" casha.";
if(n%6==1) cout<<"Topceto e v "<<a<<" casha.";
if(n%6==2) cout<<"Topceto e v "<<b<<" casha.";
if(n%6==3) cout<<"Topceto e v "<<c<<" casha.";
if(n%6==4) cout<<"Topceto e v "<<d<<" casha.";
if(n%6==5) cout<<"Topceto e v "<<e<<" casha.";
return 0;
}
