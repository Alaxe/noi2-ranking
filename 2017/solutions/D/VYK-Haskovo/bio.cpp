#include<iostream>

using namespace std;

int datavdni(int m,int d,int g)
{
    while (m!=0)
    {if (m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {d+=31;m--;}
            else if (m==2)
            {
            d+=28;m--;
            }
            else if (m==1) m--;
            else
            {
            d+=30;m--;
            }
    }
    return d;
}

int main()
{
    char neshto;
    int d1,m1,d2,m2,d3,m3,d4,m4,d=1,m=1,fiz,emo,in,brfiz=1,bremo=1,brin=1,brr=0;
    cin>>d1>>neshto>>m1>>d2>>neshto>>m2>>d3>>neshto>>m3>>d4>>neshto>>m4;
    int j=1,i=1;
    for (;i<=12;i++)
    {
        for (j=1;j<=31;j++,brfiz++,bremo++,brin++)
        {
            if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) {if (j>31) {j-=31;break;}}
            else if (i==2)
            {
            if (j>28) {j-=28;break;}
            }
            else
            {
            if (j>30) {j-=30;break;}
            }

            if (d1==j && m1==i) {fiz=brfiz%23;}
            if (d2==j && m2==i) {emo=bremo%28;}
            if (d3==j && m3==i) {in=brin%33;}

        }
    }
    if (fiz==0) fiz++;
    if (emo==0) emo++;
    if (in==0) in++;
    d1=2;d2=2;d3=2;d=1;
    bool no=false;
    int g=2017;
    while (no==false)
    {
        if (d1==fiz && d2==emo && d3==in) break;
       d1++; if (d1>23) d1=1;
       d2++; if (d2>28) d2=1;
       d3++; if (d3>33) d3=1;
       d++;

    }
    cout<<d<<"\n";
    return 0;
}
/*
23/7 29/10 23/7 10/2









        ___/
     __(  _
    /__(___)


    _/
   <@
*/
