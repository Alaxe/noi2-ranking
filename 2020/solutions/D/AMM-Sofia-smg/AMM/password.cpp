#include <bits/stdc++.h>
using namespace std;
string a;
int s[26];
int main ()
{
    int i,br=1,k,j=0-1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a;
    for(i=0;i<a.size();i++)
    {
        s[a[i]-'a']++;
    }
    for(i=0;i<a.size()-1;i++)
    {
        if(a[i]==a[i+1])
        {
            br++;
        }
        else
        {
            br=1;
        }
       if(br>2)
       {
           br=1;
           while(true)
           {
               s[a[i+1]-'a']--;
               k=a[i+1]-'a';
               a[i+1]=((a[i+1]-'a')+1)%26+'a';
               s[a[i+1]-'a']++;
               if(i+3<a.size())
               {
                   if(a[i+1]!=a[i+2]&&a[i+1]!=a[i+3]&&s[a[i+1]-'a']<=a.size()/2)
                   {
                       break;
                   }
               }
               else
               {

                   if(s[a[i+1]-'a']<=a.size()/2)
                   {
                       break;
                   }
               }
               s[a[i+1]-'a']--;
               s[k]++;
           }
       }

    }
    for(i=0;i<26;i++)
    {
        if(s[i]>a.size()/2)
        {
            j=i;
        }
    }
    for(i=0;i<a.size()&&j>=0;i++)
    {
        if(a[i]==j+'a'&&s[j]>a.size()/2)
        {
            while(true)
           {
               s[j]--;
               a[i+1]=((a[i+1]-'a')+1)%26+'a';
               s[a[i+1]-'a']++;
               if(i+3<a.size())
               {
                   if(a[i+1]!=a[i+2]&&a[i+1]!=a[i+3]&&s[a[i+1]-'a']<=a.size()/2)
                   {
                       break;
                   }
               }
               else
               {

                   if(s[a[i+1]-'a']<=a.size()/2)
                   {
                       break;
                   }
               }
               s[a[i+1]-'a']--;
               s[j]++;
           }
        }
    }

    cout<<a;
    return 0;
}
