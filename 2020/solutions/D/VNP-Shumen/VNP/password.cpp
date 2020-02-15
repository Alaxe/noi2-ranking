#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    string usp;
    cin>>usp;
    stack<char>sfp;
    int len=usp.size();
    for(int i=len-1;i>=0;i--)
    {
       if(sfp.size()<2)
       {
           sfp.push(usp[i]);
       }
       else
       {
           if (usp[i]==usp[i+1]&&usp[i]==usp[i+2]&&usp[i]!='a')
           {
               usp[i]='a';
           }
           else
           {
               if(usp[i]==usp[i+1]&&usp[i]==usp[i+2]&&usp[i]!='b')
               {
                   usp[i]='b';
               }
           }
           sfp.push(usp[i]);
       }
    }
    for(int i=0;i<len;i++)
    {
        if(!sfp.empty())
        {
            cout<<sfp.top()<<"";
            sfp.pop();
        }
    }
    cout<<endl;

return 0;
}
