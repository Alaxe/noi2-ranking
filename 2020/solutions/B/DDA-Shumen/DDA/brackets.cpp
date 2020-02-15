#include<iostream>
#include<stack>
#include<string>
using namespace std;

string s;
stack<char>c;
stack<char>p;

int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        c.push(s[i]);
        if(s[i]=='(')
        {
            p.push('(');
            for(int j=i+1; j<s.size(); j++)
            {
                c.push(s[j]);
                if(s[j]=='(')
                {
                    p.push('(');
                    j++;
                }
                else if(s[j]==')')
                {
                    if(p.size()==1)
                    {
                        if(s[j+1]=='*' || s[j+1]=='/')
                        {
                            while(s[j]==')' && s[j]=='&')
                            {
                                j--;
                            }
                            if(s[j]=='*' || s[j]=='/')
                            {
                                p.pop();
                                c.pop();
                                i++;
                            }
                            else
                            {
                                p.pop();
                                i++;
                            }
                        }
                    }
                    else
                    {
                        p.pop();
                        j++;
                    }
                }
            }
        }
        else i++;
    }
    while(!c.empty())
    {
        cout<<c.top();
        c.pop();
    }
    return 0;
}
