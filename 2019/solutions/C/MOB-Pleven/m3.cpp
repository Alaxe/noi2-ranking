#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s,k;
    cin>>s>>k;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    float k1=k;
    float a1=a,b1=b,c1=c,d1=d;
    if(s*4*d<k){cout<<fixed<<setprecision(3)<<k1/(s*4)<<' '<<k1/(s*4)<<' '<<k1/(s*4)<<' '<<k1/(s*4);return 0;}
    int n=k/(d*4);
    k%=(d*4);
    k1=k;
    if(k == 0)
    {
        cout<<fixed<<setprecision(3)<<d1<<' '<<d1<<' '<<d1<<' '<<d1;
        return 0;
    }
    if(n%4==0)
    {

        if(k<=a)
            cout<<fixed<<setprecision(3)<<k1<<" 0.000 0.000 0.000";
        else if(k<2*a1)
            cout<<fixed<<setprecision(3)<<a1<<' '<<k1-a1<<" 0.000 0.000";
        else if(k<=2*c1)
            cout<<fixed<<setprecision(3)<<k1/2<<' '<<k1/2<<" 0.000 0.000";
        else if(k<=2*c1+b1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<c1<<' '<<k1-2*c1<<' '<<"0.000";
        else if(k<=2*c1+2*b1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<c1<<' '<<b1<<' '<<k1-2*c1-b1;
        else if(k<=4*c1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<c1<<' '<<(k1-2*c1)/2<<' '<<(k1-2*c1)/2;
        else
            cout<<fixed<<setprecision(3)<<k1/4<<' '<<k1/4<<' '<<k1/4<<' '<<k1/4;
    }
    if(n%4==1)
    {
        if(k<=b)
            cout<<fixed<<setprecision(3)<<k1<<" 0.000 0.000 0.000";
        else if(k<=b1+a1)
            cout<<fixed<<setprecision(3)<<b1<<' '<<k1-b1<<" 0.000 0.000";
        else if(k<=b1+2*a1)
            cout<<fixed<<setprecision(3)<<b1<<' '<<a1<<' '<<k1-a1-b1<<' '<<"0.000";
        else if(k<=b1*3)
            cout<<fixed<<setprecision(3)<<b1<<' '<<(k1-b1)/2<<' '<<(k1-b1)/2<<' '<<"0.000";
        else if(k<=3*c1)
            cout<<fixed<<setprecision(3)<<k1/3<<' '<<k1/3<<' '<<k1/3<<' '<<"0.000";
        else if(k<=4*c1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<c1<<' '<<c1<<' '<<k1-3*c1;
        else
            cout<<fixed<<setprecision(3)<<k1/4<<' '<<k1/4<<' '<<k1/4<<' '<<k1/4;
    }
    if(n%4==2)
    {
        if(k<=b)
            cout<<fixed<<setprecision(3)<<k1<<" 0.000 0.000 0.000";
        else if(k<=b1+b1)
            cout<<fixed<<setprecision(3)<<b1<<' '<<k1-b1<<" 0.000 0.000";
        else if(k<=2*c1)
            cout<<fixed<<setprecision(3)<<k1/2<<' '<<k1/2<<' '<<"0.000"<<' '<<"0.000";
        else if(k<=2*c1+a1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<c1<<' '<<k1-2*c1<<' '<<"0.000";
        else if(k<=2*c1+2*a1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<c1<<' '<<a1<<' '<<k1-2*c1-a1;
        else if(k<=4*c1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<c1<<' '<<(k1-2*c1)/2<<' '<<(k1-2*c1)/2;
        else
            cout<<fixed<<setprecision(3)<<k1/4<<' '<<k1/4<<' '<<k1/4<<' '<<k1/4;
    }
    if(n%4==3)
    {
        if(k<=c)
            cout<<fixed<<setprecision(3)<<k1<<" 0.000 0.000 0.000";
        else if(k<=a1+c1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<k1-c1<<" 0.000 0.000";
        else if(k<=c1+2*a1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<a1<<' '<<k1-c1-a1<<' '<<"0.000";
        else if(k<=c1+2*b1)
            cout<<fixed<<setprecision(3)<<c1<<' '<<(k1-c1)/2<<' '<<(k1-c1)/2<<' '<<"0.000";
        else if(k<=c1+b1*3)
            cout<<fixed<<setprecision(3)<<c1<<' '<<b1<<' '<<b1<<' '<<k1-c1-2*b1;
        else if(k<=c1*4)
            cout<<fixed<<setprecision(3)<<c1<<' '<<(k1-c1)/3<<' '<<(k1-c1)/3<<' '<<(k1-c1)/3;
        else
            cout<<fixed<<setprecision(3)<<k1/4<<' '<<k1/4<<' '<<k1/4<<' '<<k1/4;
    }
    return 0;
}
///HELLO
