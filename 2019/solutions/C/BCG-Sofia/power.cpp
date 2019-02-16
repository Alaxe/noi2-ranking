#include<bits/stdc++.h>
using namespace std;
int n,k,c;
int a[45];
int pr[14]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};

string umn(string s,int h)
{
    string x="";
    int ost=0;
    for(int i=s.size()-1;i>=0;--i)
    {
        x=char(((s[i]-'0')*h+ost)%10+'0')+x;
        ost=((s[i]-'0')*h+ost)/10;
    }
    if(ost!=0)x=char(ost+'0')+x;
    return x;
}
string po(string s,int a)
{
    int f=a%10;
    int e=a/10;
    string sub1=umn(s,f);
    string sub2=umn(s,e);
    sub2+="0";
    string otg="";
    int i=sub1.size()-1;
    int j=sub2.size()-1;
    int ost=0;
    while(true)
    {
            if(i<0 and j<0)break;
int s1=0;
int s2=0;
         if(i<0) s1=0;
        else int s1=i;
           if(j<0)s2=0;
        else s2=j;
           otg=char((s1+s2+ost)%10)+otg;
           ost=(s1+s2+ost)/10;
           i--;
           j--;
    }
    if(ost!=0)otg=char(ost+'0')+otg;
    return otg;
}
int main ()
{
ios_base::sync_with_stdio(0);

cin>>n>>k;
for(int i=0;i<n;++i)
{
    cin>>c;
    for(int p=0; p<14 || c!=1;++p)
    {
        int br=0;
        while(c%pr[p]==0)
        {
            c=c/pr[p];
            br++;
        }

        a[pr[p]]=max(a[pr[p]],br);
    }
}
string m="1";
for(int i=0;i<14;++i)
{
    if(a[pr[i]]!=0)
    {
        int l=(a[pr[i]]+k)/k;
    for(int j=0;j<l;++j)m=po(m,pr[i]);
    }
}
cout<<m<<endl;

    return 0;
}
