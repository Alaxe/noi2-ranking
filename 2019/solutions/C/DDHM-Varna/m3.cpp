#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<stdlib.h>
using namespace std;
void print(double x1,double x2,double x3,double x4)
{
    cout<<fixed<<setprecision(3)<<x1<<" ";
    cout<<fixed<<setprecision(3)<<x2<<" ";
    cout<<fixed<<setprecision(3)<<x3<<" ";
    cout<<fixed<<setprecision(3)<<x4<<"\n";
}
int main()
{
    double a,b,a1,b1,c1,c,d,s,k;
    cin>>s>>k;
    cin>>a>>b>>c>>d;
    if(4.0*s*d<=k)
    {
        cout<<fixed<<setprecision(3)<<k/(4.0*s)<<" ";
        cout<<fixed<<setprecision(3)<<k/(4.0*s)<<" ";
        cout<<fixed<<setprecision(3)<<k/(4.0*s)<<" ";
        cout<<fixed<<setprecision(3)<<k/(4.0*s)<<"\n";
        return 0;
    }
    int br,k1=floor(k),d1=floor(d);
    br=k1/(4*d1)+1;
    k1%=(4*d1);
    if(k1==0)
    {
        br--;
        k1=4*d1;
    }
    k=k1;d=d1;
    if(k==4*d)
    {
        cout<<d<<".000 "<<d<<".000 "<<d<<".000 "<<d<<".000\n";
        return 0;
    }
    if(k>=4*c)
    {
        print(k/4.0,k/4.0,k/4.0,k/4.0);
        return 0;
    }
    switch(br%4)
    {
        case 0:
        {
            a1=c;b1=a;c1=b;
            if(k<=a1)
            {
                print(k,0,0,0);
                return 0;
            }
            k-=a1;
            if(k<=b1)
            {
                print(a1,k,0,0);
                return 0;
            }
            k-=b1;
            if(k<=b1)
            {
                print(a1,b1,k,0);
                return 0;
            }
            k-=b1;
            if(k<=2*(c1-b1))
            {
                print(a1,b1+k/2.0,b1+k/2.0,0);
                return 0;
            }
            k-=2*(c1-b1);
            if(k<=c1)
            {
                print(a1,c1,c1,k);
                return 0;
            }
            k-=c1;
            print(a1,c1+k/3.0,c1+k/3.0,c1+k/3.0);
            return 0;
        }
        case 1:
        {
            a1=a;b1=c;c1=b;
            if(k<=a1)
            {
                print(k,0,0,0);
                return 0;
            }
            k-=a1;
            if(k<=a1)
            {
                print(a1,k,0,0);
                return 0;
            }
            k-=a1;
            if(k<=(b1-a1)*2)
            {
                print(a1+k/2.0,a1+k/2.0,0,0);
                return 0;
            }
            k-=(b1-a1)*2;
            if(k<=c1)
            {
                print(b1,b1,k,0);
                return 0;
            }
            k-=c1;
            if(k<=c1)
            {
                print(b1,b1,c1,k);
                return 0;
            }
            k-=c1;
            print(b1,b1,c1+k/2.0,c1+k/2.0);
            return 0;
        }
        case 2:
        {
            a1=b;b1=a;c1=c;
            if(k<=a1)
            {
                print(k,0,0,0);
                return 0;
            }
            k-=a1;
            if(k<=b1)
            {
                print(a1,k,0,0);
                return 0;
            }
            k-=b1;
            if(k<=b1)
            {
                print(a1,b1,k,0);
                return 0;
            }
            k-=b1;
            if(k<=(a1-b1)*2)
            {
                print(a1,b1+k/2.0,b1+k/2.0,0);
                return 0;
            }
            k-=(a1-b1)*2;
            if(k<=3*(c1-a1))
            {
                print(a1+k/3.0,a1+k/3.0,a1+k/3.0,0);
                return 0;
            }
            k-=3*(c1-a1);
            print(c1,c1,c1,k);
            return 0;
        }
        case 3:
        {
            a1=b;b1=c;c1=a;
            if(k<=a1)
            {
                print(k,0,0,0);
                return 0;
            }
            k-=a1;
            if(k<=a1)
            {
                print(k,a1,0,0);
                return 0;
            }
            k-=a1;
            if(k<=(b1-a1)*2)
            {
                print(a1+k/2.0,a1+k/2.0,0,0);
                return 0;
            }
            k-=(b1-a1)*2;
            if(k<=c1)
            {
                print(b1,b1,k,0);
                return 0;
            }
            k-=c1;
            if(k<=c1)
            {
                print(b1,b1,c1,k);
                return 0;
            }
            k-=c1;
            print(b1,b1,c1+k/2.0,c1+k/2.0);
            return 0;
        }
    }
return 0;
}
