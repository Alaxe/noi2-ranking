#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
unsigned long long s,t,z,i=0,br=0,key=0,otg=0,ch,limit=1,z2=0,s2,p,j=0,t2,z3=0,z1,num=1;
void func(unsigned long long from, unsigned long long to)
{
    while(from<to)
    {
        key=0;
        br=0;
        ch=from;
        while(ch>0)
        {
            if(ch%2==0) br++;
            ch=ch/2;
            if(br>z) {key=1;break;}
        }
        if(br!=z) key=1;
        if(key==0) 
        {
            otg++;
        }
        from++;
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>t>>z;
    limit=pow(2,z);
    if(limit>t) otg=0;
    else
    {
    //cout<<limit<<endl;
    z1=z;
    s2=s;
    while(s2>0)
    {
        s2=s2/2;
        z2++;
    }
    t2=t;
    while(t2>0)
    {
        t2=t2/2;
        z3++;
    }
    //cout<<"z2= "<<z2<<" z3= "<<z3<<endl;
    while(j<60)
    {
        j++;
        if(z2>z1) {z1++;continue;}
        if(z3==z1+1) break;
        p=max(z1-z,z);
        //cout<<"z1= "<<z1<<endl;
        num=1;
        p++;
        //cout<<"p= "<<p<<endl;
        while(p<=z1)
        {
            num=num*p;
            //cout<<"  num= "<<num<<endl;
            p++;
        }
        
        p=min(z1-z,z);
        //cout<<"k p= "<<p<<endl;
        while(p>0)
        {
            num=num/p;
            //cout<<"  num= "<<num<<endl;
            p--;
        }
        //cout<<"num= "<<num<<endl;
        z1++;
        otg+=num;
        
    }
    
    //cout<<"otg= "<<otg<<endl;
    i=pow(2,z2);
    //cout<<"s+1= "<<s+1<<" i= "<<i<<endl;
    //cout<<"otg= "<<otg<<endl;
    func(s+1,i);
    //cout<<"otg= "<<otg<<endl;
    i=pow(2,z1);
    //cout<<"i= "<<i<<" t= "<<t<<endl;
    //cout<<"otg= "<<otg<<endl;
    func(i,t+1);
    //cout<<"otg= "<<otg<<endl;
    }
    cout<<otg<<endl;
    return 0;
}
/*
1481437

Process returned 0 (0x0)   execution time : 0.445 s
Press any key to continue.

*/