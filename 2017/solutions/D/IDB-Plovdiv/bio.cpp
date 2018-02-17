#include <iostream>
using namespace std;
int main ()
{
    int df,mf,de,me,di,mi,f,e,i,dc,mc,c;
    long long br=0;
    char lf,le,li,lc;
    cin>>df>>lf>>mf>>de>>le>>me>>di>>li>>mi>>dc>>lc>>mc;
    if(mf==1)f=df;
    if(mf==2)f=df+31;
    if(mf==3)f=df+59;
    if(mf==4)f=df+90;
    if(mf==5)f=df+120;
    if(mf==6)f=df+151;
    if(mf==7)f=df+181;
    if(mf==8)f=df+212;
    if(mf==9)f=df+243;
    if(mf==10)f=df+273;
    if(mf==11)f=df+304;
    if(mf==12)f=df+334;
    if(me==1)e=de;
    if(me==2)e=de+31;
    if(me==3)e=de+59;
    if(me==4)e=de+90;
    if(me==5)e=de+120;
    if(me==6)e=de+151;
    if(me==7)e=de+181;
    if(me==8)e=de+212;
    if(me==9)e=de+243;
    if(me==10)e=de+273;
    if(me==11)e=de+304;
    if(me==12)e=de+334;
    if(mi==1)i=di;
    if(mi==2)i=di+31;
    if(mi==3)i=di+59;
    if(mi==4)i=di+90;
    if(mi==5)i=di+120;
    if(mi==6)i=di+151;
    if(mi==7)i=di+181;
    if(mi==8)i=di+212;
    if(mi==9)i=di+243;
    if(mi==10)i=di+273;
    if(mi==11)i=di+304;
    if(mi==12)i=di+334;
    if(mc==1)c=dc;
    if(mc==2)c=dc+31;
    if(mc==3)c=dc+59;
    if(mc==4)c=dc+90;
    if(mc==5)c=dc+120;
    if(mc==6)c=dc+151;
    if(mc==7)c=dc+181;
    if(mc==8)c=dc+212;
    if(mc==9)c=dc+243;
    if(mc==10)c=dc+273;
    if(mc==11)c=dc+304;
    if(mc==12)c=dc+334;
    int fn=f+22,en=e+27,in=i+32;
    for(;fn-c>0;)
    {
        fn+=23;
        en+=28;
        in+=33;
    }
    for(;in!=fn&&in!=en&&fn!=en;)
    {
        fn+=23;
        en+=28;
        in+=33;
    }
    br=fn-c;
    cout<<br<<endl;

    return 0;
}

