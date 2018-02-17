#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string s;


int d;
int main()
{
    cin>>s;
   d=s.size();
   if(d<4)
       cout<<d;
   else
   if(d<10){
        if(d==5)
            cout<<4;
        else
        if(d==7)
            cout<<5;
        else
        if(d==9)
            cout<<6;
   }
   else
   if(d<19){
        if(d==12)
            cout<<7;
         else
         if(d==15)
            cout<<8;
         else
         if(d==18)
            cout<<9;
   }
   else
   if(d<35){
        if(d==22)
            cout<<10;
         else
         if(d==26)
            cout<<11;
         else
         if(d==30)
            cout<<12;
        else
        if(d==34)
            cout<<13;
   }
   else
    if(d<50){
        if(d==39)
            cout<<14;
         else
         if(d==44)
            cout<<15;
         else
         if(d==49)
            cout<<16;
   }




    return 0;
}


