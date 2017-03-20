#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int nod(int a,int b)
{
    int r;
    while (b!=0)
    {
        a=b;
        b=r;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c1,c2,c3,f,min;
    int d1,m1,d2,m2,d3,m3,d,m;
    char r;
    cin>>d1>>r>>m1>>d2>>r>>m2>>d3>>r>>m3>>d>>r>>m;
    f=d;
    while (m!=1)
    {
        if (m==2) f=f+28;
        else if (m==4||m==6||m==9||m==11) f=f+30;
        else f=f+31;
        m--;
    }
    c1=d1;
    while (m1!=1)
    {
        if (m1==2) c1=c1+28;
        else if (m1==4||m1==6||m1==9||m1==11) c1=c1+30;
        else c1=c1+31;
        m1--;
    }
    c2=d2;
    while (m2!=1)
    {
        if (m2==2) c2=c2+28;
        else if (m2==4||m2==6||m2==9||m2==11) c2=c2+30;
        else c2=c2+31;
        m2--;
    }
    c3=d3;
    while (m3!=1)
    {
        if (m3==2) c3=c3+28;
        else if (m3==4||m3==6||m3==9||m3==11) c3=c3+30;
        else c3=c3+31;
        m3--;
    }
    min=f;
    if(c1<min) min=c1;
    if(c2<min) min=c2;
    if(c3<min) min=c3;

    f=f-min;
    c1=c1-min;
    c2=c2-min;
    c3=c3-min;

    min=c1;
    if(c2<min) min=c2;
    if(c3<min) min=c3;
    f=min;

    c1=c1-min;
    c2=c2-min;
    c3=c3-min;

    c1=c1%23;
    c2=c2%28;
    c3=c3%33;

    int N=0;
    if (c1==0)
        {for (int i=23;i<25*30;i=i+23)
        {
            if (i%28==c2) {N=i;break;}
        }
        for (int i=N;i<N*35;i=i+N)
        {
            if (i%33==c3) {N=i;break;}
        }
    }
    else if (c3==0)
    {
        for (int i=33;i<30*35;i=i+33)
        {
            if (i%28==c2) {N=i;break;}
        }
        for (int i=N;i<N*25;i=i+N)
        {
            if (i%23==c1) {N=i;break;}
        }
    }
    else if (c2==0)
    {
        for (int i=28;i<25*30;i=i+28)
        {
            if (i%23==c1) {N=i;break;}
        }
        for (int i=N;i<N*35;i=i+N)
        {
            if (i%33==c3) {N=i;break;}
        }
    }

    cout<<N+f<<endl;

    return 0;
}
/*
1/1 1/1 1/1 1/1
23/7 29/10 23/7 10/2
*/
