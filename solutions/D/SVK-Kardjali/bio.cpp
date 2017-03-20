#include <iostream>
#include <cstring>
using namespace std;
int main ()
{int fd,fm,ed,em,pd,pm,sd,sm,f[1000],e[1000],p[1000],f1=0,e1=0,p1=0,i=0,j=0,h=0,ch=0;
char c1,c2,c3,c4;
cin>>fd>>c1>>fm>>ed>>c2>>em>>pd>>c3>>pm>>sd>>c4>>sm;

for(int i=1;i<=fm;i++)
{
if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)f1+=31;
else if(i==4 || i== 6 || i==9 || i==11)f1+=30;
else if(i==2)f1+=28;
}
f1+=fd;

for(int i=1;i<=em;i++)
{
if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)e1+=31;
else if(i==4 || i== 6 || i==9 || i==11)e1+=30;
else if(i==2)e1+=28;
}
e1+=ed;

for(int i=1;i<=pm;i++)
{
if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)p1+=31;
else if(i==4 || i== 6 || i==9 || i==11)p1+=30;
else if(i==2)p1+=28;
}
f[i]=f1/23;
i++;
while(f[i]!=356)
{
f[i]=f[i-1]+23;
i++;
}

e[j]=e1/28;
j++;
while(e[j]!=365)
{
  e[j]=e[j-1]+28;
  j++;
}
p[h]=p1/33;
h++;
while(p[h]!=365)
{
  p[h]=p[h-1]+33;
  h++;
}

for(int i1=0;i1<i;i1++)
{
for(int j1=0;j1<j;j1++)
{
for(int h1=0;h1<h;h1++)
{
if(f[i1]==e[j1] && f[i1]==p[h1] && e[j1]==p[h1]){cout<<f[i1]<<" "<<e[j1]<<" "<<p[h1]<<endl;}
}
}
}

return 0;
}
