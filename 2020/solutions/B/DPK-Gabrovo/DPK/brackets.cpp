#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main ()
{
    string a;
    getline(cin,a);
    int n=a.size();
    char pr='1';
    for (int i=0;i<n;i++)
    {
        if (a[i]=='&')a.erase(i,1);
    }
    while (true)
    {
        bool f=0;
        int s=a.find('(');
        int i=s;
        while (true)
        {
           i--;
           if (a[i]!='(')continue;
           else if(a[i]=='-')
           {
               f=1;
               break;
           }
           else if(a[i]=='*' or a[i]=='/')
           {
               int j=s;
               while (true)
               {
                   j++;
                   if (a[j]=='(')continue;
                   if (a[j]=='-' or a[j]=='+')f=1;
                   break;
               }
               if (f==0)
               {
                   j=s+3;
                  while (true)
               {
                   j++;
                   if (a[j]!=')')continue;
                   else
                   break;
               }
               }
           }
           else break;
        }
    }
    cout<<a<<endl;
    return 0;
}
