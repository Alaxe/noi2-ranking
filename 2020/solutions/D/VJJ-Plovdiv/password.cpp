#include<iostream>
#include<string>
using namespace std;
int main()
{int m[26]={0},k,br=0,b=0;
string s;
cin>>s;
k=s.size();
cout<<k<<endl;
for (int i=0;i<k;i++)
{
    m[s[i]-'a']++;
}
for (int i=0;i<26;i++)
{
    if (m[i]==0)
    { for (int ii=1;ii<k;ii++)
        {   cout<<s[ii-1]<<" "<<s[ii]<<" "<<br<<endl;
            if (s[ii]==s[ii-1]) br++;
          if (br>2) {s[ii-br+2]=i+'a';br=0;}
        }if (br>=2) s[k-br+1]=i+'a';
    break;
    }}
 for (int i=0;i<26;i++) m[i]=0;
for (int i=0;i<k;i++)
{
    m[s[i]-'a']++;
}
for(int i=0;i<26;i++)
{
    if (m[i]>k/2)
    {   cout<<m[i]-k/2<<endl;
        for (int g=0;g<26;g++)
        {
            if (m[g]==0)
            {
                s[b]=g+'a';
                s[b+1]=g+'a';
                m[g]=m[g]+2;
                break;
            }

        }
        b=b+3;
    }
}
cout<<s<<endl;
}


