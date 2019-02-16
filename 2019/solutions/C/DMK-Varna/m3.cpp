#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,d,S,obem,L,obsek,nom,ost,p,x,y,z,h[4];
    cin>>S>>obem;
    cin>>a>>b>>c>>d;
    L=4*S;
    obsek=4*d;
    nom=obem/obsek;
    ost=obem%obsek;
    if (ost!=0)nom++;
    if (ost==0){cout<<d<<".000 "<<d<<".000 "<<d<<".000 "<<d<<".000"<<endl;}
    x=a;
    y=b;
    z=c;
    if (nom%4==1){b=z;c=y;}
    if (nom%4==2){a=y;b=x;}
    if (nom%4==3){a=y;b=z;c=x;}
    if (nom%4==0){a=z;b=x;c=y;}
    if (ost>a){ost-=a;h[1]=a;}
    else {cout<<ost<<".000 0.000 0.000 0.000"<<endl;return 0;}
    if (a<b)
    {
        if (ost>2*b){h[1]=b;h[2]=b;ost-=(2*b);}
        else
        {
            if (ost<a)
            {
                h[2]=ost;
                cout<<h[1]<<".000 "<<h[2]<<".000 0.000 0.000"<<endl;
                return 0;
            }
            if (ost>=a)
            {
                h[2]=a;
                ost-=a;
                if (ost%2==0)
                {
                    h[1]+=(ost/2);
                    h[2]+=(ost/2);
                    cout<<h[1]<<".000 "<<h[2]<<".000 0.000 0.000"<<endl;
                    return 0;
                }
                else
                {
                    h[1]+=(ost/2);
                    h[2]+=(ost/2);
                    cout<<h[1]<<".500 "<<h[2]<<".500 0.000 0.000"<<endl;
                    return 0;
                }
            }
        }
    }
    if (a>b)
    {
        if (ost<=b)
        {
             cout<<h[1]<<".000 "<<ost<<".000 0.000 0.000"<<endl;
             return 0;
        }
        else
        {
            ost-=b;
            h[2]=b;
        }
    }
    if (b<c)
    {
        if (ost>3*c){h[1]=c;h[2]=c;ost-=(3*c);}
        else
        {
            if (ost<b)
            {
                h[3]=ost;
                cout<<h[1]<<".000 "<<h[2]<<".000 "<<h[3]<<".000 0.000"<<endl;
                return 0;
            }
            if (ost>=b)
            {
                h[3]=b;
                ost-=b;
                if (ost%2==0)
                {
                    h[2]+=(ost/2);
                    h[3]+=(ost/2);
                    cout<<h[1]<<".000 "<<h[2]<<".000 "<<h[3]<<".000 0.000"<<endl;
                    return 0;
                }
                else
                {
                    h[2]+=(ost/2);
                    h[3]+=(ost/2);
                    cout<<h[1]<<".000 "<<h[2]<<".500 "<<h[3]<<".500 0.000"<<endl;
                    return 0;
                }
            }
        }
    }
    if (b>c)
    {
        if (ost<=c)
        {
             cout<<h[1]<<".000 "<<h[2]<<".000 "<<ost<<".000 0.000"<<endl;
             return 0;
        }
        else
        {
            ost-=c;
            h[3]=c;
        }
    }
            if (ost<c)
            {
                h[4]=ost;
                cout<<h[1]<<".000 "<<h[2]<<".000 "<<h[3]<<".000 "<<h[4]<<".000"<<endl;
                return 0;
            }
            if (ost>=c)
            {
                h[4]=c;
                ost-=c;
                if (ost%2==0)
                {
                    h[3]+=(ost/2);
                    h[4]+=(ost/2);
                    cout<<h[1]<<".000 "<<h[2]<<".000 "<<h[3]<<".000 "<<h[4]<<".000"<<endl;
                    return 0;
                }
                else
                {
                    h[3]+=(ost/2);
                    h[4]+=(ost/2);
                    cout<<h[1]<<".000 "<<h[2]<<".000 "<<h[3]<<".500 "<<h[4]<<".500"<<endl;
                    return 0;
                }
            }
}
