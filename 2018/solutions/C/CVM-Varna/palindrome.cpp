#include<bits/stdc++.h>
using namespace std;
bool f;
string add(string s,int sz)
{
    bool pr=1;f=0;
    for(int i=sz-1;i>=0;i--)
    {
        int x=s[i]-'0'+pr;
        pr=x/10;
        x%=10;
        s[i]=char(x+'0');
    }
    if(pr){s="1"+s;sz++;f=1;}
    return s;
}
int cmp(string a,string b,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int sz;
    string s;
    cin>>s;
    sz=s.size();
    s=add(s,sz); if(f) sz++;
    if(sz&1)
    {
        string s1=s.substr(0,sz/2),s2=s.substr(sz/2+1,sz/2),s3; s3=s1;
        char ch=s[sz/2];
        reverse(s1.begin(),s1.end());
        if(cmp(s1,s2,sz/2)<0){
            if(ch=='9'){s3=add(s3,sz/2);ch='0';}
            else ch++;
        }
        cout<<s3<<ch;
        reverse(s3.begin(),s3.end());
        cout<<s3<<endl;
    }
    else
    {
        string s1=s.substr(0,sz/2),s2=s.substr(sz/2,sz/2),s3; s3=s1;
        reverse(s1.begin(),s1.end());
        if(cmp(s1,s2,sz/2)<0){s3=add(s3,sz/2);}
        cout<<s3;
        reverse(s3.begin(),s3.end());
        cout<<s3<<endl;
    }
    return 0;
}
