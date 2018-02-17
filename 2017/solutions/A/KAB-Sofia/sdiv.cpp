#include<iostream>
#include<string.h>
using namespace std;
 char s[10000];
int main()
{
cin>>s;
int l=0;
while(s[l]!='\0')
{
    l++;
}
int n,m;
cin>>n>>m;
int gl[n],pom[n];
for(int q=0;q<n;q++)
{
    gl[q]=0;
    pom[q]=0;
}
int y;
for(int cif=0;cif<l;cif++)
{
    for(int x=0;x<n;x++)
    {
        y=(10*x+s[cif])%n;
        gl[y]=(gl[y]+pom[x])%m;
    }
    gl[s[cif]%n]=(gl[s[cif]%n]+1)%m;
    for(int q=0;q<n;q++)
    {
    pom[q]=gl[q];
    }
}
cout<<gl[0]<<endl;
return 0;
}
