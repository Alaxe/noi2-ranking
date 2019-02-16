#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void print(double a,double b, double c, double d)
{
cout<<fixed<<setprecision(3)<<a<<" ";
cout<<fixed<<setprecision(3)<<b<<" ";
cout<<fixed<<setprecision(3)<<c<<" ";
cout<<fixed<<setprecision(3)<<d<<" ";
}
double s,k,a,b,c,d;
long long cont=1,sector;
int main()
{
cin>>s>>k;
cin>>a>>b>>c>>d;
if(4*d<k)
{cont=(k/(4*d)+1);while(k>4*d)k-=4*d;}
sector=cont%4;
if(cont>s)print(d,d,d,d);
if(sector==1)swap(b,c);
if(sector==2)swap(a,b);
if(sector==3){swap(a,c);swap(a,b);}
if(sector==4){swap(a,b);swap(a,c);}
///----------------------
if(sector==3  && k>2*b+c){print(a,b,c+(k-2*b-c)/2,c+(k-2*b-c)/2);return 0;}
if(sector==1 && k>2*b+c){print(b,b,c,k-c-b-b);return 0;}
if(sector==2 && k>3*c){print(c,c,c,k-3*c);return 0;}
if(sector==4 && k>a+2*c && k-a-3*b>0){print(a,c+(k-a-3*c)/3,c+(k-a-3*c)/3,k-a-2*c+(k-a-3*c)/3);return 0;}
else if(sector==4 && k>a+2*c){print(a,c,c,k-a-2*c);return 0;}
///----------------------
if(sector==1 && k>2*b){print(b,b,k-2*b,0);return 0;}
if(sector==2 && k>a+b && k>3*a){print(a+(k-3*a)/3,b+(k-3*a)/3,b+(k-3*a)/3,0);return 0;}
else if(sector==2 && k>a+b){print(a,b+(k-a-2*b)/2,b+(k-a-2*b)/2,0);return 0;}
if(sector==3 && k>2*b){print(b,b,k-2*b,0);return 0;}
if(sector==4 && k>a+b){print(a,b+(k-a-2*b)/2,b+(k-a-2*b)/2,0);return 0;}
///----------------------
if(k-2*a>0)
    {
        if(sector==1 && k>a){print(a+(k-2*a)/2,a+(k-2*a)/2,0,0);return 0;}
        if(sector==3 && k>a){print(a+(k-2*a)/2,a+(k-2*a)/2,0,0);return 0;}
    }
else{
if(k>a){print(a,k-a,0,0);return 0;}
}
return 0;
}
