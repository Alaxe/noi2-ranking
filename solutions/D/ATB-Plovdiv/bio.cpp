#include<bits/stdc++.h>
using namespace std;
int main()
{char aa,aaa,aaaa,aaaaa;
int c[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int z,p,pp,br=0,q1=0,q2=0,q3=0,q4=0,i,a1,b1,a2,b2,a3,b3,a4,b4;
cin>>a1>>aa>>b1;
cin>>a2>>aaa>>b2;
cin>>a3>>aaaa>>b3;
cin>>a4>>aaaaa>>b4;
for(i=0;i<b1-1;i++)q1+=c[i];
for(i=0;i<b2-1;i++)q2+=c[i];
for(i=0;i<b3-1;i++)q3+=c[i];
for(i=0;i<b4-1;i++)q4+=c[i];
q1+=a1;
q2+=a2;
q3+=a3;
q4+=a4;
if(q1==q2&&q2==q3)cout<<q1*21252-q4+1<<endl;
if(q1==q3&&q2!=q3)
{p=q1%28;
pp=q2%28;
while(pp!=p)
{p=(3+p)%28;
br++;
}
cout<<br*759-q4+q1<<endl;
}
if(q1==q2&&q2!=q3)
{p=q1%33;
pp=q3%33;
while(pp!=p)
{p=(17+p)%33;
br++;
}
cout<<br*644-q4+q1<<endl;
}
if(q3==q2&&q2!=q1)
{p=q2%23;
pp=q1%23;
while(pp!=p)
{p=(4+p)%23;
br++;
}
cout<<br*924-q4+q2<<endl;
}
if(q1!=q2&&q1!=q3&&q2!=q3)
{p=q1%28;
pp=q2%28;
while(p!=pp)
{
p=(23+p)%28;
br++;
}
q1=23*br+q1;
q2=q1;
br=0;
p=q1%33;
pp=q3%33;
while(pp!=p)
{p=(17+p)%33;
br++;
}
cout<<br*644-q4+q1<<endl;
}
return 0;
}
