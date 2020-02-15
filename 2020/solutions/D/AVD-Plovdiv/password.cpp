#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
       int br=1;
       for(int j = 0; j < i; j++)
       {
           if(s[j] == s[i])
           {
               br++;
           }
       }
       for(int j = i+1; j < s.size(); j++)
       {
           if(s[j] == s[i])
           {
               br++;
           }
       }
       int m=0,a[br];
       for(int j = 0; j < i; j++)
       {
           if(s[j] == s[i])
           {
               a[m]=j;
               m++;
           }
       }
       a[m] = i;
       m++;
       for(int j = i+1; j < s.size(); j++)
       {
           if(s[j] == s[i])
           {
               a[m]=j;
               m++;
           }
       }
       bool nujda = false;
       int z = 0,n;
       do
       {
           n=z;
           do
           {
               z++;
           }
           while(a[i]+1 == a[i+1]);
           if(z-n+1 > 2)
           {
               nujda = true;
           }
           if(br > s.size()/2)
           {
               nujda = true;
           }
           int c = n+2;
           string d = "a";
           if(nujda == true)
           {
               for(int j = 1; j <= br / 3; j++)
               {
                   s.replace(c, 1, d);
                   c=c+3;
               }
           }
       }
       while(z != br-1);
    }
    cout << s << endl;
    return 0;
}
