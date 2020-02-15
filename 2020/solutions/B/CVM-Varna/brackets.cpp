#include<bits/stdc++.h>
using namespace std;
bool f[200001];
bool lvl[200001];
string s; int n;
void skob(int x,int y,int lv)
{
    if(!lvl[lv]) f[x]=f[y]=1;
    else
    {
        bool f1=0,f2=0,sk1=0,sk2=0;
        if(x>0)
        {
            if(s[x-1]=='+') f1=1;
            if(s[x-1]=='(') sk1=1;
        }
        else f1=1;
        if(y<n-1)
        {
            if(s[y+1]=='+'||s[y+1]=='-') f2=1;
            if(s[y+1]==')') sk2=1;
        }
        else f2=1;
        f[x]=f[y]=(f1&f2)||(f1*sk2)||(f2&sk1);
    }
}
void solve()
{
    memset(f,0,sizeof(f));
    memset(lvl,0,sizeof(lvl));
    stack<int> st; int lv=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='('){st.push(i); lvl[++lv]=0;}
        else if(s[i]==')')
        {
            int x=st.top(); st.pop();
            skob(x,i,lv); lv--;
        }
        else if(s[i]=='+'||s[i]=='-') lvl[lv]=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
    n=s.size();
    solve();
    string a="";
    for(int i=0;i<n;i++)
    {
        if(!f[i]) a+=s[i];
    }
    for(int j=0;j<5;j++)
    {
        s=a;
        n=s.size();
        solve();
        a="";
        for(int i=0;i<n;i++)
        {
            if(!f[i]) a+=s[i];
        }
        if(a==s) break;
    }
    cout<<a<<endl;
    return 0;
}
/**

((&+&)*&)/&

&+(&*(&-&)-(&-&))

&+((((&/&))))/&

&+((((&-&))))/&

&+((((((((&+&))))))))-&*&

((((((&+&))))-(((&-&)))))

((((&-((&*&/((((&+&))-&))))))+&))

&-((((((((&-((&*&/((((&+&))-&))))))+&))/&))+&))

*/
