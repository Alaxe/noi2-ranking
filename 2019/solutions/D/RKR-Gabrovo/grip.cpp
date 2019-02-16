#include<iostream>
using namespace std;
int main()
{
    int d=0,m=0,y=0,n,dd=0,mm=0,yy=0,md[13],brd=0,ost,i,bre=0,iz;
    char v;
    for (i=1;i<=10;i++)
    {
       cin.get(v);
       if (v>='0' && v<='9' && bre==0) d=d*10+(v-'0');
       if (v>='0' && v<='9' && bre==1) m=m*10+(v-'0');
       if (v>='0' && v<='9' && bre==2) y=y*10+(v-'0');
       if (v=='/') bre++;
       //if (v=='n/') break;
    }
    cin>>n;
 /////////////////////////////////////////////////////////////////////////
 md[1]=31;
 if (y=2020) md[2]=29;
 else md[2]=28;
 md[3]=31;
 md[4]=30;
 md[5]=31;
 md[6]=30;
 md[7]=31;
 md[8]=31;
 md[9]=30;
 md[10]=31;
 md[11]=30;
 md[12]=31;
 /////////////////////////////////////////////////////////////////////////
 if (y=2019) iz=6;
 else iz=5;
 ost=((d*m)-iz)%7;
 for (i=1;i<=n;i++)
 {
    ost++;
    brd++;
    if (ost==5) {ost=0;brd=brd+2;}
 }
 d=d+brd;
 while (d>md[m])
 {
        dd=d%md[m];
        mm=m++;
        m++;
        d=dd;
 }
 yy=y;
 if (mm==13) {mm=1;yy=y++;}
 cout<<dd<<"."<<mm<<"."<<yy<<endl;
 return 0;
}
