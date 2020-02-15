#include<bits/stdc++.h>

using namespace std;

int main()
{
    const int nmax=200010;
    int a[nmax];
    memset(a, 0, sizeof a);
    stack<pair<char, int>> st;
    string s, k="", x="";
    vector<char> sign;
    cin>>s;
    int sz=s.size(), cnt1=1, cnt2=1;
    //for(int i=0; i<sz; ++i) if(s[i]!='&') k+=s[i];
    //cout<<k<<endl;
    //sz=k.size();
    for(int i=0; i<sz; ++i)
    {
        if(s[i]==')')
        {
            if(st.top().first=='(')
            {
                a[st.top().second]=1;
                a[i]=1;
                st.pop();
            }
            else
            {
                while(st.top().first!='(') st.pop();
                st.pop();
            }
        }
        else st.push(make_pair(s[i], i));
    }
    for(int i=0; i<sz; ++i) if(a[i]==0) k+=s[i];

    sz=k.size();
    //cout<<k<<endl;
    memset(a, 0, sizeof a);
    for(int i=0; i<sz; ++i)
    {
        if(k[i]=='&') continue;
        if(k[i]!=')') st.push(make_pair(k[i], i));
        else
        {
            bool mal=0, big=1;
            while(st.top().first!='(')
            {
                if(st.top().first=='+'||st.top().first=='-') mal=1;
                else big=1;
                st.pop();
            }
            if((k[i+1]=='*'||k[i+1]=='/')&&mal==0) a[st.top().second]=1, a[i]=1;
            //if((s[i+1]=='*'||s[i+1]=='/')&&big==1) a[st.top().second]=1, a[i]=1;
            if((k[i+1]=='+'||k[i+1]=='-')) a[st.top().second]=1, a[i]=1;
        }
    }
    while(!st.empty()) st.pop();
    for(int i=0; i<sz; ++i) if(a[i]==0) x+=k[i];
    sz=x.size();
    memset(a, 0, sizeof a);
    cout<<x<<endl;

    return 0;
}
/*
((&+&)*&)/&
&+((((&/&))))/&
&+(&*(&-&)-(&-&))
((&*&)+&)
 */
