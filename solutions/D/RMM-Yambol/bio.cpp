# include <iostream>
# include <cstdio>
using namespace std;
int main()
{
string s;
cin>>s;
//cout<<s<<endl;
int a[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int i=0;
int t1=0,m1=0,t2=0,m2=0,t3=0,m3=0,t4=0,m4=0;
while(s[i]!='/')
{
    t1=t1*10+s[i]-'0';
    i++;
}
i++;
while(i<s.size())
{
    m1=m1*10+s[i]-'0';
    i++;
}
   // cout<<t1<<" "<<m1<<endl;
t1=a[m1-1]+t1;
i=0;
cin>>s;
//cout<<s;
while(s[i]!='/')
{
    t2=t2*10+s[i]-'0';
    i++;
}
i++;

while(i<s.size())
{
    m2=m2*10+s[i]-'0';
    i++;
}
   // cout<<t2<<" "<<m2<<endl;
t2=a[m2-1]+t2;
cin>>s;
//cout<<s;
i=0;
while(s[i]!='/')
{
    t3=t3*10+s[i]-'0';
    i++;
}
i++;
while(i<s.size())
{
    m3=m3*10+s[i]-'0';
    i++;
}
   // cout<<t3<<" "<<m3<<endl;
t3=a[m3-1]+t3;
cin>>s;
//cout<<s;
i=0;
while(s[i]!='/')
{
    t4=t4*10+s[i]-'0';
    i++;
}
i++;
while(i<s.size())
{
    m4=m4*10+s[i]-'0';
    i++;
}
   // cout<<t4<<" "<<m4<<endl;
t4=a[m4-1]+t4;
//cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;

m1=t1%23;
m2=t2%28;
m3=t3%33;
//cout<<m1<<" "<<m2<<" "<<m3<<endl;
int k1,k2,k3;
k1=m3-m1;
k2=m3-m2;
k3=0;
i=33;
while(1)
{
    if((i+m3-m1)%23==0&&(i+m3-m2)%28==0)break;
    i+=33;

}
t4=i+m3-t4;
if(t4<0)t4+=21252;
printf("%d\n",t4);
}

