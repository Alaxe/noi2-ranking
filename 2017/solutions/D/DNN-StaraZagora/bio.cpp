#include <iostream>
using namespace std;

int main()
{
	int dfiz, mfiz, demo, memo, dint, mint, dstart, mstart;
	char naklonena;
	cin>>dfiz>>naklonena>>mfiz>>demo>>naklonena>>memo>>dint>>naklonena>>mint>>dstart>>naklonena>>mstart;
//cout<<dfiz<<mfiz<<demo<<memo<<dint<<mint<<dstart<<mstart;
    int timefiz, timeemo, timeint, timestart;
    int summesec = 0;
    for (int i=1; i<13; i++)
    {
        if (mfiz==i)
        {
            timefiz=summesec+dfiz;
            break;
        }
        else if (i==1) summesec+=31;
        else if (i==2) summesec+=28;
        else if (i==3) summesec+=31;
        else if (i==4) summesec+=30;
        else if (i==5) summesec+=31;
        else if (i==6) summesec+=30;
        else if (i==7) summesec+=31;
        else if (i==8) summesec+=31;
        else if (i==9) summesec+=30;
        else if (i==10) summesec+=31;
        else if (i==11) summesec+=30;
        else if (i==12) summesec+=31;
    }
    summesec=0;
    for (int i=1; i<13; i++)
    {
        if (memo==i)
        {
            timeemo=summesec+demo;
            break;
        }
        else if (i==1) summesec+=31;
        else if (i==2) summesec+=28;
        else if (i==3) summesec+=31;
        else if (i==4) summesec+=30;
        else if (i==5) summesec+=31;
        else if (i==6) summesec+=30;
        else if (i==7) summesec+=31;
        else if (i==8) summesec+=31;
        else if (i==9) summesec+=30;
        else if (i==10) summesec+=31;
        else if (i==11) summesec+=30;
        else if (i==12) summesec+=31;
    }
    summesec=0;
    for (int i=1; i<13; i++)
    {
        if (mint==i)
        {
            timeint=summesec+dint;
            break;
        }
        else if (i==1) summesec+=31;
        else if (i==2) summesec+=28;
        else if (i==3) summesec+=31;
        else if (i==4) summesec+=30;
        else if (i==5) summesec+=31;
        else if (i==6) summesec+=30;
        else if (i==7) summesec+=31;
        else if (i==8) summesec+=31;
        else if (i==9) summesec+=30;
        else if (i==10) summesec+=31;
        else if (i==11) summesec+=30;
        else if (i==12) summesec+=31;
    }
    summesec=0;
    for (int i=1; i<13; i++)
    {
        if (mstart==i)
        {
            timestart=summesec+dstart;
            break;
        }
        else if (i==1) summesec+=31;
        else if (i==2) summesec+=28;
        else if (i==3) summesec+=31;
        else if (i==4) summesec+=30;
        else if (i==5) summesec+=31;
        else if (i==6) summesec+=30;
        else if (i==7) summesec+=31;
        else if (i==8) summesec+=31;
        else if (i==9) summesec+=30;
        else if (i==10) summesec+=31;
        else if (i==11) summesec+=30;
        else if (i==12) summesec+=31;
    }
//cout<<timefiz<<' '<<timeemo<<' '<<timeint<<endl;
    while (1)
    {
        if (timefiz>timestart && timeemo>timestart && timeint>timestart) {timefiz-=timestart; timeemo-=timestart; timeint-=timestart; break;}
        timefiz+=23; timeemo+=28; timeint+=33;
    }
    while (timefiz!=timeemo && timefiz!=timeint && timeemo!=timeint)
    {
        timefiz+=23; timeemo+=28; timeint+=33;
    }
    cout<<timefiz<<endl;
	return 0;
}