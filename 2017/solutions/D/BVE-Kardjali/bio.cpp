#include<iostream>
#include<string>
using namespace std;
int main()
{
string s1,s2,s3,s4;
int l1,l2,l3,l4;
int d1=0,m1=0,d2=0,m2=0,d3=0,m3=0,d4=0,m4=0;
char ch;
cin>>s1>>s2>>s3>>s4;
l1=s1.size();
l2=s2.size();
l3=s3.size();
l4=s4.size();
int sum1=0,sum2=0,sum3=0,sum4=0;
int i=0,j=0,ik=0,ij=0,ik1=0,ij1=0;
while(s1[i]!='/')
{
d1=d1*10+(s1[i]-'0');
i++;
}
for(j=i+1;j<l1;j++)
m1=m1*10+(s1[j]-'0');

i=0;
while(s2[i]!='/')
{
d2=d2*10+(s2[i]-'0');
i++;
}
for(j=i+1;j<l2;j++)
m2=m2*10+(s2[j]-'0');

i=0;
while(s3[i]!='/')
{
d3=d3*10+(s3[i]-'0');
i++;
}
for(j=i+1;j<l3;j++)
m3=m3*10+(s3[j]-'0');

i=0;
while(s4[i]!='/')
{
d4=d4*10+(s4[i]-'0');
i++;
}
for(j=i+1;j<l4;j++)
m4=m4*10+(s4[j]-'0');
for(i=1;i<m1;i++)
{
if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)sum1+=31;
else if(i==4||i==6||i==9||i==11)sum1+=30;
else if(i==2)sum1+=28;
}
sum1+=d1;
for(i=1;i<m2;i++)
{
if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)sum2+=31;
else if(i==4||i==6||i==9||i==11)sum2+=30;
else if(i==2)sum2+=28;
}
sum2+=d2;
for(i=1;i<m3;i++)
{
if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)sum3+=31;
else if(i==4||i==6||i==9||i==11)sum3+=30;
else if(i==2)sum3+=28;
}
sum3+=d3;
for(i=1;i<m4;i++)
{
if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)sum4+=31;
else if(i==4||i==6||i==9||i==11)sum4+=30;
else if(i==2)sum4+=28;
}
sum4+=d4;
int sl1,sl2,sl3,e[100],f[100],p[100];
e[0]=sum1%23;
f[0]=sum2%28;
p[0]=sum3%33;
int i1,i2,i3;
for(i1=1;;i1++)
{
sl1=e[i1-1]+23;
if(sl1<=365)e[i1]=sl1;
else break;
}
for(i2=1;;i2++)
{
sl2=f[i2-1]+28;
if(sl2<=365)f[i2]=sl2;
else break;
}
for(i3=1;;i3++)
{
sl3=p[i3-1]+33;
if(sl3<=365)p[i3]=sl3;
else break;
}
int j1,j2,j3,l=0;
for(j1=0;j1<i1;j1++)
for(j2=0;j2<i2;j2++)
for(j3=0;j3<i3;j3++)
if(e[j1]==f[j2]==p[j3])
{cout<<e[j1]<<" "<<f[j2]<<" "<<p[j3]<<endl;l=1;}
cout<<l<<endl;
return 0;

}

