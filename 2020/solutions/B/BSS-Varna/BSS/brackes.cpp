#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int a[100000],k=0,next;
    int b[100000];
    bool d[100000];
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        ///cout<<k<<' '<<a[k]<<' '<<b[k]<<' '<<s[i]<<endl;
        if(s[i]=='&')continue;
        else if(s[i]=='(')
        {
            k++;
            if(i==0)a[k]=1;
            else if(s[i-1]=='(')a[k]=1;
            else if(s[i-1]=='+')a[k]=1;
            else a[k]=2;
        }
        else if(s[i]=='+')
        {
            b[k]=2;
        }
        else if(s[i]=='-')
        {
            b[k]=2;
        }
        else if(s[i]=='*')
        {
            b[k]=max(b[k],1);
        }
        else if(s[i]=='/')
        {
            b[k]=max(b[k],1);
        }
        ///cout<<k<<' '<<a[k]<<' '<<b[k]<<' '<<s[i]<<endl;
        if(s[i]==')')
        {
            if(i==s.size()-1)next=1;
            else if(s[i+1]==')')next=1;
            else if(s[i+1]=='+' || s[i+1]=='-')next=1;
            else next=2;
            if((a[k]==1 && next==1) || b[k]==1)d[k]=0;
            else d[k]=1;
            k--;
        }

    }
    k=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            k++;
            if(d[k]==1)cout<<'(';
        }
        else if(s[i]==')')
        {
            if(d[k]==1)cout<<')';
            k--;

        }
        else cout<<s[i];
    }
    cout<<endl;
}
/**
((&+&)*&)/&

&+(&*(&-&)-(&-&))

&+((((&/&))))/&
*/

