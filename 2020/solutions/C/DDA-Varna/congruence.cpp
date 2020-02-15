#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
string s1,s2;
vector<char>v;
bool b[30];
int p,q;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>s;
p=s.size();
for(int i=0;i<p;i++)
{
    if(!b[s[i]-'A'+1]){b[s[i]-'A'+1]=1;v.push_back(s[i]);}
}
sort(v.begin(),v.end());
q=v.size();
for(int i=0;i<p;i++)
{
    for(int j=0;j<q;j++)
    {
        if(v[j]==s[i])
        {
            s1=s1+(char)('A'+j);
            s2=s2+(char)('Z'-q+j+1);
        }
    }
}
cout<<s1<<endl;
cout<<s2<<endl;
}
