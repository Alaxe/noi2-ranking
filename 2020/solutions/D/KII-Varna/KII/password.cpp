#include<iostream>
#include<cstring>
using namespace std;
int len(string a)
{int i;
    while(a[i]!='\n')
   {if(a[i]<'a')break;
   i++;}
}
int fr[32];
int main(){
string a;
int l,i,st;
cin>>a;
l=len(a);
for(i=1;i<l;i++)
{if(a[i]==a[i-1])st++;
if(st==3)
{if(a[i-1]!='a'&&a[i+1]!='a')a[i]='a';
if(a[i-1]!='a'&&a[i+1]=='a'){if(a[i-1]!='b'&&a[i+1]=='a')a[i]='b';
else a[i]='c';}}
}
cout<<a<<endl;}
