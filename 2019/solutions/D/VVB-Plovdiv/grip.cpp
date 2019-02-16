#include<bits/stdc++.h>
using namespace std;
long long pos,d,m,y,n,x;
long long f_day(long long d,long long m)
{
 long long k;
 if(m==1) k=2;
 else
 if(m==2) k=5;
 else
 if(m==3) k=5;
 else
 if(m==4) k=1;
 else
 if(m==5) k=3;
 else
 if(m==6) k=6;
 else
 if(m==7) k=1;
 else
 if(m==8) k=4;
 else
 if(m==9) k=7;
 else
 if(m==10) k=2;
 else
 if(m==11) k=5;
 else
 if(m==12) k=7;
 long long r=d%7-1+k;
 if(r>7)r-=7;
 return r;
}
int main()
{
 string s,s1;
 cin>>s;
 cin>>n;
 pos=s.find("/");
 s1=s.substr(0,pos+1);
 d=atoll(s1.c_str());
 s.erase(0,pos+1);
 pos=s.find("/");
 s1=s.substr(0,pos+1);
 m=atoll(s1.c_str());
 s.erase(0,pos+1);
 y=atoll(s.c_str());
 long long r=f_day(d,m);
 int i=1;
 if(r==6){x+=2;r=1;i++;}
 if(r==7){x+=1;r=1;i++;}

 for(;i<=n;x++)
 {
   if(r>7) r-=7;
   if(r==6||r==7){r++;continue;}
   else {r++;i++;}
 }
 if(r==6) x+=2;
 d+=x;
 if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d>31)) {d-=31;m++;}
 else
 if((m==4||m==6||m==9||m==11)&&(d>30)) {d-=30;m++;}
 else
 if((m==2)&&(d>28)&&(y==2019)){d-=28;m++;}
 else
 if((m==2)&&(d>29)&&(y==2020)){d-=29;m++;}
 if(m>12) {y++;m-=12;}
 if(d<10) cout<<0<<d<<".";
 else cout<<d<<".";
 if(m<10) cout<<0<<m<<".";
 else cout<<m<<".";
 cout<<y<<endl;
 return 0;
}
