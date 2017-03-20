#include <iostream>
using namespace std;
int main()
{
int d1,m1,d2,m2,d3,m3,d4,m4,o=0,g1=2017,g2=2017,g3=2017,mxd1,mxd2,mxd3;
char c,c1,c2,c3;
cin>>d1>>c>>m1>>d2>>c1>>m2>>d3>>c2>>m3>>d4>>c3>>m4;
do
{
    d1=d1+23;
    d2=d2+28;
    d3=d3+33;
            o=o+33;
            if(m1==2)
            {
                if(g1%4==0)mxd1=29;
                else mxd1=28;
            }
            else if(m1!=2&&m1%2==0)mxd1=30;
                else mxd1=31;
               if(m2==2)
            {
                if(g2%4==0)mxd2=29;
                else mxd2=28;
            }
            else if(m2!=2&&m2%2==0)mxd2=30;
                else mxd2=31;
   if(m3==2)
            {
                if(g3%4==0)mxd3=29;
                else mxd3=28;
            }
            else if(m3!=2&&m3%2==0)mxd3=30;
                else mxd3=31;
if(d1>mxd1){d1=d1-mxd1;m1++;}
if(d2>mxd2){d2=d2-mxd2;m2++;}
if(d3>mxd3){d3=d3-mxd3;m3++;}
if(m1>12){m1=m1-12;g1++;}
if(m2>12){m2=m2-12;g2++;}
if(m3>12){m2=m2-12;g2++;}
}
while(d1!=d2&&d2!=d3&&d1!=d3);
    cout<<o<<endl;
    }
