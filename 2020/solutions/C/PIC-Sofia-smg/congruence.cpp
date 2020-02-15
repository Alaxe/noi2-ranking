#include<iostream>
#include<string>
using namespace std;
int main()
{
string w,ws;
cin>>w;ws=w;
int l=w.size(),m[l];
for(int i=0;i<l-1;i++)
    {
    for(int j=i;j<l;j++)
        {
        if(ws[i]>ws[j]){swap(ws[i],ws[j]);}
        }
    }
short int mark=0;
for(int i=0;i<l;i++)
    {
    if(ws[i]==ws[i-1]){goto e;}
    for(int j=0;j<l;j++)
        {
        if(ws[i]==w[j]){m[j]=mark;}
        }
    mark++;
    e:;
    }
for(int i=0;i<l;i++){cout<<char('A'+m[i]);}
cout<<endl;
for(int i=0;i<l;i++){cout<<char('Z'-mark+m[i]+1);}
cout<<endl;s
return 0;
}
