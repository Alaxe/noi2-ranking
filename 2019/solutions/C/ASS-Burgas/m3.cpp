#include<bits/stdc++.h>
using namespace std;
void s3(int a) ///vrushta s 3 sled tochkata
{
    int aa,br=0;
    aa=a;
    while(aa>0)
    {
        aa/=10;
        br++;
    }
    double c=double(a);
    setprecision(3+br);
    cout<<c<<" ";
    ///zashto ne stava drobno
}
///nqmam vreme za sluchaq s razdelqneto
int main()
{
    int s,k,a,b,c,d,Vs,brpulni,ost,teks,st1,st2,st3;
    cin>>s>>k>>a>>b>>c>>d;
    Vs=4*d;
    brpulni=k/Vs;
    ost=k-(brpulni*Vs);
    teks=brpulni+1;
    if (teks%k==1||(s==1&&teks%k==0))
    {
        st1=a;
        st2=c;
        st3=b;
    }
    else if (teks%k==2||(s==2&&teks%k==0))
    {
        st1=b;
        st2=a;
        st3=c;
    }
    else if (teks%k==3||(s==3&&teks%k==0))
    {
        st1=b;
        st2=c;
        st3=a;
    }
    else
    {
        st1=c;
        st2=a;
        st3=b;
    }
    if (ost>=st1+st2+2*st3)
    {
        s3(st1);
        s3(st2);
        s3(st3);
        s3(st3);
    }
    else if(ost>=st1&&ost<st2)
    {
        s3(st1);
        s3(ost-st1);
        s3(0);
        s3(0);
    }
    else if(ost>=st2+st1&&ost<st3)
    {
        s3(st1);
        s3(st2);
        s3((ost-st1-st2));
        s3(0);
    }
    else
    {
        s3(st1);
        s3(st2);
        s3(st3);
        s3(ost-st1-st2-st3);
    }
    return 0;
}
