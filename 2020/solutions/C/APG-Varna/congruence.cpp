#include<bits/stdc++.h>
#define endl '\n'
struct string2
{
    char a;
    int i;
} s1[15000000],s2[15000000];
bool cmp(string2 a,string2 b)
{
    return a.a<b.a;
}
using namespace std;
bool t[300];
string s,s3,s4;
int br=0;
vector <int> a[3];
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    char c='A';
    cin>>s;
    s3=s;
    s4=s;
    for(int i=0; i<s.size(); i++)
    {
        s1[i].a=s[i];
        s1[i].i=i;
        if(t[s[i]]==0)
        {
            t[s[i]]=1;
            br++;
        }
    }
    sort(s1,s1+s.size(),cmp);
    s3[s1[0].i]='A';
    for(int i=1; i<s.size(); i++)
    {
        if(s1[i].a==s1[i-1].a)s3[s1[i].i]=c;
        else
        {
            c++;
            s3[s1[i].i]=c;
        }
    }
    cout<<s3<<endl;
    for(int i=0; i<s3.size(); i++)
    {
        s4[i]=('Z'-br+(s3[i]-'A'+1));
    }
    cout<<s4<<endl;
    return 0;
}
