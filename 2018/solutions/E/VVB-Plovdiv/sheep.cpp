#include<iostream>
using namespace std;
int main()
{
 long long n,l,p1=-1,p2=-1,p3=-1,maxi,put=0,ch=1,brc,ch2,a,b,put2,flag,flag2;
 cin>>n;
 cin>>l;
 ch2=1;

 if(l==1)
 {
  cin>>p1;
  if(p1!=1) put++;
  while(put!=n)
   {
    ch2=ch;
    while(ch)
    {
     if(ch2<=9&&ch2>=1&&ch2!=p1) {flag+=2;}
     else
     if(ch%10!=p1) {flag++;}
     ch/=10;
    }
    if(flag==2) {put++;maxi=ch2;}
    flag=0;
    ch=ch2+1;
   }
 }
  if(l==2)
 {
  cin>>p1;
  cin>>p2;
  if(p1!=1&&p2!=1) put++;
 while(put!=n)
   {
    ch2=ch;
    while(ch)
    {
     if(ch2<=9&&ch2>=1&&ch2!=p1&&ch2!=p2) {flag+=2;}
     else
     if(ch%10!=p1&&ch%10!=p2) {flag++;}
     ch/=10;
    }
    if(flag==2) {put++;maxi=ch2;}
    flag=0;
    ch=ch2+1;
   }
 }
 if (l==3)
 {
  if(p1!=1&&p2!=1&&p3!=1) put++;
  cin>>p1;
  cin>>p2;
  cin>>p3;
  while(put!=n)
   {
    ch2=ch;
    while(ch)
    {
     if(ch2<=9&&ch2>1&&ch2!=p1&&ch2!=p2&&ch2!=p3) {flag+=2;}
     else
     if(ch%10!=p1&&ch%10!=p2&&ch%10!=p3) {flag++;}
     ch/=10;
    }
    if(flag==2) {put++;maxi=ch2;}
    flag=0;
    ch=ch2+1;
   }
 }
 cout<<maxi<<endl;
 return 0;
}
