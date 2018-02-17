#include<iostream>
using namespace std;
int palendrom(int r)
{if(r<10)
{
    return 2;
}
if(r>9 and r<100){
if (r/10==r%10)
{return 2;}

}
if(r>99 and r<1000){
if (r/100==r%10)
{

 return 2;}}
 if(r>999 and r<10000){
if (r/1000==r%10)
{
    if(r%1000/100==r/10%10)
    {
        return 2;
    }
}
}
if(r>9999 and r<100000){
if (r/10000==r%10)
{
    if(r%10000/1000==r/10%10)
    {
        return 2;
    }
}
}
if(r>99999 and r<1000000){
if (r/100000==r%10)
{
    if(r%100000/10000==r/10%10)
    {if(r%10000/1000==r/100%10){
        return 2;
    }}
}
}
}

int main()
{ int N,a1,a2,pr=1,otg=0,ch1,ch2;
cin>>N;
a1=N-1;
a2=N-1;
for(int i=0;i<=a1;i++)
{
    for(int c=0;c<=a2;c++)
    {
     pr=palendrom((a1-i)*(a2-c));
     if(pr==2)
     {if( otg<=(a1-i)*(a2-c))
         {otg=(a1-i)*(a2-c);
         ch1=a1-i;
         ch2=a2-c;}
     }
    }
}
cout<<ch1<<" "<<ch2<<endl;
cout<<otg;
return 0;

}
