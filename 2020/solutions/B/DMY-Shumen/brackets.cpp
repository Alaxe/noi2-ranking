#include <bits/stdc++.h>
using namespace std;

string s;
int a[200000], sz;

void print()
{
    for(int i=0;i<sz;i++)
    {
        if(a[i]==1)
        {
            cout<<s[i];
        }
    }
    cout<<endl;
}

void brackets()
{
    int p=2;
    char z;
    sz=s.size();
    for(int i=0;i<sz;i++)
    {
        if(s[i]=='&')
        {
            a[i]=1;
        }
        else if(s[i]=='(')
        {
            if(z=='*'||z=='/') p=1;
            else if(z=='-') p=-1;
            else p=0;
        }
        else if(s[i]==')')
        {
            if(p==1)
            {
                if(z=='+'||z=='-')
                {
                    a[i]=1;
                }
            }
            else if(p==-1)
            {
                if(z=='*'||z=='/')
                {
                    a[i]=1;
                }
            }
        }
        else
        {
           z=s[i];
           a[i]=1;
        }
    }
    for(int i=sz-1;i<=0;i--)
    {
        if(s[i]=='(')
        {
            if(p==1)
            {
                if(z=='+'||z=='-')
                {
                    a[i]=1;
                }
            }
            else if(p==-1)
            {
                if(z=='*'||z=='/')
                {
                    a[i]=1;
                }
            }
        }
        else if(s[i]==')')
        {
            if(z=='*'||z=='/') p=1;
            else if(z=='-') p=-1;
            else p=0;
        }
        else if(a[i]!='&')
        {
           z=s[i];
        }
    }
    for(int i=0;i<sz;i++)
    {
        if(s[i]!='&'&&s[i]!='('&&s[i]!=')') z=s[i];
        if(z=='*')
        {
            if(s[i+1]=='('&&(s[i+3]=='+'||s[i+3]=='-'))
            {
                a[i+1]=1;
                a[i+5]=1;
            }
        }
        else if(s[i]=='(')
        {
            if((s[i+2]=='+'||s[i+2]=='-')&&s[i+5]=='*')
            {
                a[i]=1;
                a[i+4]=1;
            }
        }
        else if(s[i]==')')
        {
            int j=i+1;
            while(s[j]==')')
            {
                a[i]=0;
                j++;
            }
        }
        else if(s[i]=='(')
        {
            int j=i+1;
            while(s[j]=='(')
            {
                a[i]=0;
                j++;
            }
        }
    }
    print();
}

int main()
{
    cin>>s;
    brackets();
    return 0;
}
