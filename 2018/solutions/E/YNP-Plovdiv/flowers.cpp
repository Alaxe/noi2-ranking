#include<iostream>
using namespace std;
int main()
{
    long long n,a,q,t,f1,f3,f2,f4,f5,f6,f7,f8,maxi,r1,r2,r3,r4,r5,r6,r7,r8,s;
    cin>>n;
    if(n==5)
    {
        cin>>f1>>f2>>f3>>f4>>f5;
        maxi=f1;
        if(maxi<f2)maxi=f2;
        if(maxi<f3)maxi=f3;
        if(maxi<f4)maxi=f4;
        if(maxi<f5)maxi=f5;
        r1=maxi-f1;
        r2=maxi-f2;
        r3=maxi-f3;
        r4=maxi-f4;
        r5=maxi-f5;
        s=r1+r2+r3+r4+r5;
    }
    if(n==4)
    {
        cin>>f1>>f2>>f3>>f4;
        maxi=f1;
        if(maxi<f2)maxi=f2;
        if(maxi<f3)maxi=f3;
        if(maxi<f4)maxi=f4;
        r1=maxi-f1;
        r2=maxi-f2;
        r3=maxi-f3;
        r4=maxi-f4;
        s=r1+r2+r3+r4;
    }
    if(n==3)
    {
        cin>>f1>>f2>>f3;
        maxi=f1;
        if(maxi<f2)maxi=f2;
        if(maxi<f3)maxi=f3;
        r1=maxi-f1;
        r2=maxi-f2;
        r3=maxi-f3;
        s=r1+r2+r3;
    }
        if(n==2)
    {
        cin>>f1>>f2;
        maxi=f1;
        if(maxi<f2)maxi=f2;
        r1=maxi-f1;
        r2=maxi-f2;
        s=r1+r2;
    }
        if(n==6)
    {
        cin>>f1>>f2>>f3>>f4>>f5>>f6;
        maxi=f1;
        if(maxi<f2)maxi=f2;
        if(maxi<f3)maxi=f3;
        if(maxi<f4)maxi=f4;
        if(maxi<f5)maxi=f5;
        if(maxi<f6)maxi=f6;
        r1=maxi-f1;
        r2=maxi-f2;
        r3=maxi-f3;
        r4=maxi-f4;
        r5=maxi-f5;
        r6=maxi-f6;
        s=r1+r2+r3+r4+r5+r6;
    }
            if(n==7)
    {
        cin>>f1>>f2>>f3>>f4>>f5>>f6>>f7;
        maxi=f1;
        if(maxi<f2)maxi=f2;
        if(maxi<f3)maxi=f3;
        if(maxi<f4)maxi=f4;
        if(maxi<f5)maxi=f5;
        if(maxi<f6)maxi=f6;
        if(maxi<f7)maxi=f7;
        r1=maxi-f1;
        r2=maxi-f2;
        r3=maxi-f3;
        r4=maxi-f4;
        r5=maxi-f5;
        r6=maxi-f6;
        r7=maxi-f7;
        s=r1+r2+r3+r4+r5+r6+f7;
    }
    if(n==7)
    {
        cin>>f1>>f2>>f3>>f4>>f5>>f6>>f7;
        maxi=f1;
        if(maxi<f2)maxi=f2;
        if(maxi<f3)maxi=f3;
        if(maxi<f4)maxi=f4;
        if(maxi<f5)maxi=f5;
        if(maxi<f6)maxi=f6;
        if(maxi<f7)maxi=f7;
        if(maxi<f8)maxi=f8;
        r1=maxi-f1;
        r2=maxi-f2;
        r3=maxi-f3;
        r4=maxi-f4;
        r5=maxi-f5;
        r6=maxi-f6;
        r7=maxi-f7;
        r8=maxi-r8;
        s=r1+r2+r3+r4+r5+r6+f7+f7;
    }
    cin>>q;
    cout<<s*q<<endl;
    return 0;
}