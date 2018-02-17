#include<iostream>
#include<string>
using namespace std;
int main()
{
string s;
cin>>s;
long long int len;
len=s.size();
long long int step=0,l=0,l1=0,lch=0,br3=0,bkz,brch=0;
if(len<=18)
{
while(len>0)
{
step++;
if(step<=3)l1++;
else if(step>=4&&step<=6)l1=l1+2;
else if(step>=7&&step<=9)l1=l1+3;
len=len-l1;
l1=0;
}
cout<<step;
}
else
{
step=0;
len=18;
while(len>0)
{
step++;
if(step<=3)l1++;
else if(step>=4&&step<=6)l1=l1+2;
else if(step>=7&&step<=9)l1=l1+3;
len=len-l1;
l1=0;
}
len=s.size();
len=len-18;
bkz=4;
l=1;br3=0;lch=4;
while(len>0)
{
if(l==1&&br3==0)
{
while(bkz>0||len>0)
{
step++;
len=len-lch;
if(len==0)break;
bkz--;
if(bkz==0)break;
}
l=0;br3=1;lch++;bkz=3;
}
else if(l==0&&br3>0)
{
bkz=3;
while(bkz>0||len>0)
{
step++;
len=len-lch;
if(len==0)break;
bkz--;
if(bkz==0)break;
}
l=0;br3++;lch++;
if(br3==3){br3=0;l=1;bkz=4;}
}
}
cout<<step;
}
cout<<endl;
return 0;
}
