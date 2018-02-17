#include <iostream>
using namespace std;
int main ()
{
    long long d1, d2, d3, m1, m2, m3, d4, m4, min1, max1, min2, max2, sr1, sr2;
    long long dni1, dni2, dni3, dni4;
    char a, b, f, d;
    cin>>d1>>a>>m1>>d2>>b>>m2>>d3>>f>>m3>>d4>>d>>m4;
   if (d1==d2&&d2==d3&&d3==d4&&m1==m2&&m2==m3&&m3==m4)
    cout<<"21252"<<endl;
   else
    {
    if (m1==2) dni1=31+d1;
    if (m1==3) dni1=59+d1;
    if (m1==4) dni1=90+d1;
    if (m1==5) dni1=120+d1;
    if (m1==6) dni1=151+d1;
    if (m1==7) dni1=181+d1;
    if (m1==8) dni1=212+d1;
    if (m1==9) dni1=243+d1;
    if (m1==10) dni1=273+d1;
    if (m1==11) dni1=304+d1;
    if (m1==12) dni1=334+d1;
    if (m1==1) dni1=d1;

    if (m2==1) dni2=d2;
    if (m2==2) dni2=31+d2;
    if (m2==3) dni2=59+d2;
    if (m2==4) dni2=90+d2;
    if (m2==5) dni2=120+d2;
    if (m2==6) dni2=151+d2;
    if (m2==7) dni2=181+d2;
    if (m2==8) dni2=212+d2;
    if (m2==9) dni2=243+d2;
    if (m2==10) dni2=273+d2;
    if (m2==11) dni2=304+d2;
    if (m2==12) dni2=334+d2;

    if (m3==2) dni3=31+d3;
    if (m3==3) dni3=59+d3;
    if (m3==4) dni3=90+d3;
    if (m3==5) dni3=120+d3;
    if (m3==6) dni3=151+d3;
    if (m3==7) dni3=181+d3;
    if (m3==8) dni3=212+d3;
    if (m3==9) dni3=243+d3;
    if (m3==10) dni3=273+d3;
    if (m3==11) dni3=304+d3;
    if (m3==12) dni3=334+d3;
    if (m3==1) dni3=d3;

    if (m4==2) dni4=31+d4;
    if (m4==3) dni4=59+d4;
    if (m4==4) dni4=90+d4;
    if (m4==5) dni4=120+d4;
    if (m4==6) dni4=151+d4;
    if (m4==7) dni4=181+d4;
    if (m4==8) dni4=212+d4;
    if (m4==9) dni4=243+d4;
    if (m4==10) dni4=273+d4;
    if (m4==11) dni4=304+d4;
    if (m4==12) dni4=334+d4;
    if (m4==1) dni4=d4;

while (1==1)
{
    dni2=dni2+28;
    if ((dni2-dni1)%23==0&&(dni2-dni3)%33==0)
       {
        min1=dni2;
        cout<<min1-dni4<<endl;
    break;
    }
}

    }
    return 0;
}
