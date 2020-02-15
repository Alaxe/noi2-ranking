#include<iostream>
#include<stack>
#include<map>
using namespace std;
int minin[200010],maxout[200010];
stack<int>curr;
map<char,int>prios;
int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    prios['(']=1;
    prios[')']=1;
    prios['.']=1;
    prios['+']=3;
    prios['-']=3;
    prios['*']=5;
    prios['/']=5;
    string inp;
    cin>>inp;
    inp=".("+inp+").";
    //cout<<inp<<endl;
    for(int i=1; i<inp.size()-1; i++)
    {
        if(inp[i]=='(')
        {
            curr.push(i);
            int cpr=prios[inp[i-1]];
            if(inp[i-1]=='-' || inp[i-1]=='/')
            {
                cpr++;
            }
            maxout[i]=max(maxout[i],cpr);
        }
        else if(inp[i]==')')
        {
            maxout[curr.top()]=max(maxout[curr.top()],prios[inp[i+1]]);
            if(maxout[curr.top()]==1){
                minin[curr.top()-1]=minin[curr.top()];
            }
            curr.pop();
        }
        else if(inp[i]!='&')
        {
            if(minin[curr.top()]==0)
            {
                minin[curr.top()]=prios[inp[i]];
            }
            else
            {
                minin[curr.top()]=min(minin[curr.top()],prios[inp[i]]);
            }
        }
    }
    for(int i=1; i<inp.size()-1; i++)
    {
        if(inp[i]=='(')
        {
            curr.push(i);
            //cout<<endl<<minin[i]<<" "<<maxout[i]<<endl;
            if(minin[i]==0 || minin[i]>=maxout[i])
            {
                continue;
            }
        }
        else if(inp[i]==')')
        {
            if(minin[curr.top()]==0 || minin[curr.top()]>=maxout[curr.top()])
            {
                curr.pop();
                continue;
            }
            curr.pop();
        }
        cout<<inp[i];
    }
    cout<<endl;
    return 0;
}
