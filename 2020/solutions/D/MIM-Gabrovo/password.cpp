#include<iostream>
using namespace std;
int main ()
{
ios_base::sync_with_stdio(0);
string s;
cin>>s;
int mbr=(s.size()/2),r=s.size(),p[30]={0},br=0,br1=0,zam[10000]={0};
char a[30]={0};
for(int i='a';i<='z';i++)
{
    a[i-'a']=i;
}
for(int i=0;i<r;i++)
{

    if(s[i]>='a' && s[i]<='z')p[s[i]-'a']++;
    if(p[s[i]-'a']>mbr){s[i]='1';br1++;zam[br1]=i;}
    if(s[i]==s[i+1])
    {
        if(s[i]==s[i+1] && br==0)br++;
        br++;
        if(br>=3)
        {
            s[i+1]='1';
            br1++;
            zam[br1]=i+1;
            p[s[i+1]-'a']--;
        }
        continue;
    }
    br=0;
    if(p[s[i]-'a']>mbr){s[i]='1';br1++;zam[br1]=i;}
}
for(int i=1;i<=br1;i++)
{
    for(int j=0;j<25;j++)
    {
        p[j]++;
        if(zam[i]>=2)
        {
            if(a[j]!=s[zam[i]-1] && a[j]!=s[zam[i]-2] && p[j]<=mbr){s[zam[i]]=a[j];break;}
        }
        if(zam[i]<2 && p[j]<=mbr){s[zam[i]]=a[j];break;}
    }
}
cout<<s<<endl;
    return 0;
}
