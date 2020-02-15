# include <bits/stdc++.h>
using namespace std;
bool have[200005];
struct brackets
{
    int priority;
    int x,y;
};
brackets b[200005];
string s;
stack <int> st;
int br = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
cin>>s;
int i,j,p,q,k;
for(i=0;i<s.size();i++)
{
    if(s[i]!='('&&s[i]!=')')
    {
        if(st.empty())continue;
        if(s[i]=='&')continue;
        if(s[i]=='*'||s[i]=='/')b[st.top()].priority = min(b[st.top()].priority,2);
        if(s[i]=='+'||s[i]=='-')b[st.top()].priority = min(b[st.top()].priority,1);
    }
    if(s[i]=='(')
    {
        br++;
        b[br].x = i;
        b[br].priority=3;
        st.push(br);
    }
    if(s[i]==')')
    {
        b[st.top()].y = i;
       p = b[st.top()].x;
       q = i;
       k = st.top();
       st.pop();
       if(b[k].priority==3)
       {
           have[q]=1;
           have[p]=1;
           continue;
       }
       if(b[k].priority==2){

       if(p>0&&s[p-1]=='/')continue;

       }
       if(b[k].priority==1)
       {
           if((p>0&&(s[p-1]=='*'||s[p-1]=='/'||s[p-1]=='-')))continue;
           if(q+1<s.size()&&(s[q+1]=='*'||s[q+1]=='/'))continue;
       }
       if(!st.empty())
       {
           b[st.top()].priority = min(b[st.top()].priority,b[k].priority);
       }
       have[q]=1;
       have[p]=1;
    }
}
for(i=0;i<s.size();i++)
{
    if(!have[i])cout<<s[i];
}
cout<<endl;
    return 0;
}
