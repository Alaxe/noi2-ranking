#include<iostream>
using namespace std;
int main()
{string s;
cin>>s;
string res="";
long long int len=s.size(),br=1;
char sym='a'-1;
for(int i=0;i<len;i++)
{
    if(s[i]==s[i-1])br++;
    else br=1;
    if(br==3)
    {
        if(sym=='z')sym='a';
        else sym=(char)(sym+1);
        if(sym==s[i])sym=sym+1;
        if(sym>'z')sym='a';
        s[i]=sym;
    }
}
cout<<s<<endl;
return 0;
}
