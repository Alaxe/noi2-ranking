#include<iostream>
#include<string>
#include<stack>
using namespace std;
#define MAXL 200000
struct st
{
    int ind,val;
    bool first,second;
};
int main()
{
    bool stay[MAXL+2];
    stack<st> brack;
    st tmp;
    string s;
    cin>>s;
    int i;
    s="+"+s+"+";
    int l=s.size()-1;
    for(i=1;i<=l;i++)stay[i]=true;
    stay[0]=stay[l]=false;
    for(i=1;i<l;i++)
    {
        if(s[i]=='&')continue;
        if(s[i]=='(')
        {
            tmp.ind=i;
            tmp.first=tmp.second=false;
            if(s[i-1]=='/')tmp.val=-1;
            else if(s[i-1]=='-')tmp.val=0;
            else if(s[i-1]=='+')tmp.val=1;
            else if(s[i-1]=='*')tmp.val=2;
            else tmp.val=1;
            brack.push(tmp);
        }
        else if(s[i]!=')')
        {
             if(brack.empty())continue;
             if(s[i]=='+'||s[i]=='-')
                 brack.top().first=true;
             else brack.top().second=true;
        }
        else
        {
            if(brack.top().val==0)
            {
                if(brack.top().first==false)
                    stay[brack.top().ind]=stay[i]=false;
            }
            else if(brack.top().val==1)
            {
                if((s[i+1]=='+'||s[i+1]=='-'||s[i+1]==')')||((s[i+1]=='*'||s[i+1]=='/')&&brack.top().first==false))
                    stay[brack.top().ind]=stay[i]=false;
            }
            else if(brack.top().val==2)
            {
                if(brack.top().first==false)
                    stay[brack.top().ind]=stay[i]=false;
            }
            brack.pop();
        }
    }
    for(i=1;i<=l;i++)
        if(stay[i])cout<<s[i];
    cout<<endl;
    return 0;
}
