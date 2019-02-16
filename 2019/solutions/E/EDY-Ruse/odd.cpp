#include<iostream>
using namespace std;
int main()
{
long long a,b,i,brd=0,brch=0;
cin>>a>>b;
if(a<b)for(a=a;a<=b;a++)
       {
        for(i=1;i<=a;i++)
       {
        if(a%i==0)brd++;
       }
        if(brd%2!=0)brch++;
        brd=0;
       }
if(a>b)for(a=a;a>=b;a--)
       {
        for(i=1;i<=a;i++)
       {
        if(a%i==0)brd++;
       }
        if(brd%2!=0)brch++;
        brd=0;
       }
cout<<brch<<endl;
return 0;
}
