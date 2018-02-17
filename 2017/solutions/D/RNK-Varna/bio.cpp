#include<iostream>
using namespace std;
int main ()
{
    int d1,d2,d3,m1,m2,m3,ds,ms,i=0,j=0,br=0;
    char q,w,e,r;
    cin >> d1 >> q >> m1 >> d2 >> w >> m2 >> d3 >> r >> m3 >> ds >> e >> ms;
    if(m1==m2&&m2==m3&&m3==ms&&d1==d2&&d2==d3&&d3==ds)cout << 21252 << endl;
    else
    {
        m1--;
        m2--;
        m3--;
        ms--;
        while(m2>0)
        {
            if(m2==1||m2==3||m2==5||m2==7||m2==8||m2==10||m2==11)d2+=31;
            if(m2==4||m2==6||m2==9||m2==11)d2+=30;
            if(m2==2)d2+=28;
            m2--;
        }
        while(m3>0)
        {
            if(m3==1||m3==3||m3==5||m3==7||m3==8||m3==10||m3==12)d3+=31;
            if(m3==4||m3==6||m3==9||m3==11)d3+=30;
            if(m3==2)d3+=28;
            m3--;
        }
        while(ms>0)
        {
            if(ms==1||ms==3||ms==5||ms==7||ms==8||ms==10||ms==12)ds+=31;
            if(ms==4||ms==6||ms==9||ms==11)ds+=30;
            if(ms==2)ds+=28;
            ms--;
        }
        while(m1>0)
        {
            if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)d1+=31;
            if(m1==4||m1==6||m1==9||m1==11)d1+=30;
            if(m1==2)d1+=28;
            m1--;
        }
//--------------------------------------------------
        while(d1!=d2)
        {
            if(d1>d2)d2+=28;
            else
            {
                d1+=23;
                j+=23;
            }
        }
        while(d1!=d3)
        {
            if(d1>d3)d3+=33;
            else
            {
                d1+=644;
                j+=644;
            }
        }
        if(d1>ds)cout << d1-ds << endl;
        else cout << d1-ds+21252 << endl;



    }
    return 0;
}
