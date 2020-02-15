#include <iostream>
using namespace std;

int main()
{
int a[27]={0,},q;
string c;
char s,b[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
cin>>c;
int cs=c.size();

for(int i=2;i<cs;i++)
{
    if(c[i-2]==c[i-1] && c[i-1]==c[i])
    {
        for(int j=0;j<26;j++)
            if(c[i]!=b[j] && c[i+1]!=b[j]){c[i]=b[j];break;}
    }
}
for(int i=0;i<cs;i++)
{
    s=c[i];
    if(s=='a')a[0]++;
    else a[s-'a']++;
}
for(int i=0;i<26;i++)
{
    if(a[i]>cs/2)
    {
            for(int j=0;j<26;j++)
                if(c[i-1]!=b[j] && c[i+1]!=b[j] && a[j]>cs/2){c[i]=b[j];break;}
    }
}
cout<<c<<endl;
return 0;
}
