#include<iostream>
using namespace std;
int main()

{
int ch,m,a,b,c,br=1,w;
cin>>ch; cin>>m;
if((ch>=33) && (m<=99)){
a=ch/10;
b=ch%10;
w=ch+a+b;

for(int j=33;j<100;j++)
{

    br=br+1;
if((ch==33) && (ch<m)){

}
if(j==100) { cout<<br<<endl;}
cout<<br<<endl;
}
}

if((ch>=999) && (m<=1000)){
a=ch/100;
b=ch/10;
c=ch%10;
w=ch+a+b+c;



for(int i=100;i<1000;i++)
{
br=br+1;
if((ch<m) && (ch>=100)) {

}
if(ch==1000) { cout<<br<<endl;}
}
}
return 0;
}

