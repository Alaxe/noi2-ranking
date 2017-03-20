#include<bits/stdc++.h>
using namespace std;
int dm[13]={31,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int sum1=0,sum2=0,sum3=0,sum4=0,ii,avrg,u1=23,u2=28,u3=33;
    int chf,fm,fd,che,em=0,ed=0,chi,im,id,chs,sm,sd;
    string f,e,i,s,t;
    cin>>f>>e>>i>>s;
///opredelyane--------------------------------------------------------------------------------------
///f
    chf=f.find('/');
    t=f.substr(0,chf);
    if (t.size()==1) fm=t[0]-'0';
    else fm=(t[0]-'0')*10+t[1]-'0';
///-------------------------------------------------------------------
    t=f.substr(chf+1,f.size()-chf-1);
    if (t.size()==1) fd=t[0]-'0';
    else fd=(t[0]-'0')*10+t[1]-'0';
///f

///e
    che=e.find('/');
    t=e.substr(0,che);
    if (t.size()==1) em=t[0]-'0';
    else em=(t[0]-'0')*10+t[1]-'0';
///-------------------------------------------------------------------
    t=e.substr(che+1,e.size()-che-1);
    if (t.size()==1) ed=t[0]-'0';
    else ed=(t[0]-'0')*10+t[1]-'0';
///e

///i
    chi=i.find('/');
    t=i.substr(0,chi);
    if (t.size()==1) im=t[0]-'0';
    else im=(t[0]-'0')*10+t[1]-'0';
///-------------------------------------------------------------------
    t=i.substr(chi+1,i.size()-chi-1);
    if (t.size()==1) id=t[0]-'0';
    else id=(t[0]-'0')*10+t[1]-'0';
///i

///s
    chs=s.find('/');
    t=s.substr(0,chs);
    if (t.size()==1) sm=t[0]-'0';
    else sm=(t[0]-'0')*10+t[1]-'0';
///-------------------------------------------------------------------
    t=s.substr(chs+1,s.size()-chs-1);
    if (t.size()==1) sd=t[0]-'0';
    else sd=(t[0]-'0')*10+t[1]-'0';
///s
///opredelyane---------------------------------------------------------------------------------------
    ii=1;
    while(1)
    {
        sum1=sum1+dm[ii];
        if (ii==fm) break;
        ii++;
    }
    sum1=sum1+fd;
///
swap(em,ed);
    for (ii=1;ii<=em;ii++) sum2=sum2+dm[ii];
    sum2=sum2+ed;


///
    ii=1;
    while(1)
    {
        sum3=sum3+dm[ii];
        if (ii==im) break;
        ii++;
    }
    sum3=sum3+id;
///
        ii=1;
    while(1)
    {
        sum4=sum4+dm[ii];
        if (ii==sm) break;
        ii++;
    }
    sum4=sum4+sd;
    avrg=(sum1+sum2+sum3+sum4)/4;
    if (sum1>avrg) u1+=sum1-avrg;
    else if (sum1<avrg) u1-=avrg-sum1;
    if (sum2>avrg) u2+=sum2-avrg;
    else if (sum2<avrg) u2-=avrg-sum2;
    if (sum3>avrg) u3+=sum3-avrg;
    else if (sum3<avrg) u3-=avrg-sum3;
    ///-------------------------------
    cout<<u1*u2*u3<<endl;
    return 0;
}
/**
Input:
1/1 1/1 1/1 1/1
Output:
21252
----------------------
Input:
23/7 29/10 23/7 10/2
Output:
10789
*/
