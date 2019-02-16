#include<bits/stdc++.h>
using namespace std;
int main()
{
    double s,k,a,b,c,d,sec=1;
    cin>>s>>k;
    cin>>a>>b>>c>>d;
    if(k>d*4*s)
    {
        cout<<setprecision(3)<<fixed<<k/(4*s)<<' '<<setprecision(3)<<fixed<<k/(4*s)<<' '<<setprecision(3)<<fixed<<k/(4*s)<<' '<<setprecision(3)<<fixed<<k/(4*s)<<endl;
        return 0;
    }
    while(k>d*4)
    {
        k-=d*4;sec++;
    }
    if(sec==1)
    {
        if(k<=a)cout<<setprecision(3)<<fixed<<k<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*
        else if(k>a && k-a<=a)cout<<setprecision(3)<<fixed<<a<<' '<<setprecision(3)<<fixed<<k-a<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*
        else if(k-a>a && k<=2*c)cout<<setprecision(3)<<fixed<<k/2<<' '<<setprecision(3)<<fixed<<k/2<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*
        else if(k>2*c && k-2*c<=b)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<k-2*c<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*
        else if(k-2*c>b && k-2*c-b<=b)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<b<<' '<<setprecision(3)<<fixed<<k-2*c-b<<endl;///*
        else if(k-2*c>2*b && k<=4*c)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<(k-2*c)/2<<' '<<setprecision(3)<<fixed<<(k-2*c)/2<<endl;///*
        else if(k>4*c && k<=4*d)cout<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<endl;
    }
    else if(sec==2)
    {
        if(k<=b)cout<<setprecision(3)<<fixed<<k<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*
        else if(k>b && (k-b)<=a)cout<<setprecision(3)<<fixed<<b<<' '<<setprecision(3)<<fixed<<k-b<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*
        else if(k-b>a && k-b<=2*a)cout<<setprecision(3)<<fixed<<b<<' '<<setprecision(3)<<fixed<<a<<' '<<setprecision(3)<<fixed<<k-b-a<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*
        else if(k>b+2*a && k<=3*b)cout<<setprecision(3)<<fixed<<b<<' '<<setprecision(3)<<fixed<<((k-b)/2)<<' '<<setprecision(3)<<fixed<<((k-b)/2)<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*
        else if(k>3*b && k<=3*c)cout<<setprecision(3)<<fixed<<k/3<<' '<<setprecision(3)<<fixed<<k/3<<' '<<setprecision(3)<<fixed<<k/3<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*
        else if(k>3*c && k<=4*c)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<k-3*c<<endl;
        else if(k>4*c && k<=4*d)cout<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<endl;
    }
    else if(sec==3)
    {
        if(k<=b)cout<<setprecision(3)<<fixed<<k<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///=
        else if(k>b && k-b<=b)cout<<setprecision(3)<<fixed<<b<<' '<<setprecision(3)<<fixed<<k-b<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*=
        else if(k-b>b && k<=2*c)cout<<setprecision(3)<<fixed<<k/2<<' '<<setprecision(3)<<fixed<<k/2<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*=
        else if(k>2*c && k-2*c<=a)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<k-2*c<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*=
        else if(k-2*c>a && k-2*c-a<=a)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<a<<' '<<setprecision(3)<<fixed<<k-2*c-a<<endl;///*
        else if(k-2*c>2*a && k<=4*c)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<(k-2*c)/2<<' '<<setprecision(3)<<fixed<<(k-2*c)/2<<endl;///*
        else if(k>4*c && k<=4*d)cout<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<endl;
    }
    else if(sec==4)
    {
        if(k<=c)cout<<setprecision(3)<<fixed<<k<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*=
        else if(k>c && (k-c)<=a)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<k-c<<' '<<setprecision(3)<<fixed<<0.0<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*=
        else if(k-c>a && k-c<=2*a)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<a<<' '<<setprecision(3)<<fixed<<k-c-a<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*=
        else if(k>c+2*a && k<=2*b+c)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<((k-c)/2)<<' '<<setprecision(3)<<fixed<<((k-c)/2)<<' '<<setprecision(3)<<fixed<<0.0<<endl;///*=
        else if(k>2*b+c && k<=3*b+c)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<b<<' '<<setprecision(3)<<fixed<<b<<' '<<setprecision(3)<<fixed<<k-c-2*b<<endl;///*=
        else if(k>3*b+c && k<=4*c)cout<<setprecision(3)<<fixed<<c<<' '<<setprecision(3)<<fixed<<(k-c)/3<<' '<<setprecision(3)<<fixed<<(k-c)/3<<' '<<setprecision(3)<<fixed<<(k-c)/3<<endl;///*=
        else if(k>4*c && k<=4*d)cout<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<' '<<setprecision(3)<<fixed<<k/4<<endl;///*=
    }
}
/**
3 25
1 2 3 5
*/
