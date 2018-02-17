#include<bits/stdc++.h>
using namespace std;
long long n,del,t,i,br,ost;
string s;

int delene (string s, long long del)
{
    int i,ch=0,ch1=0,test,test1,br1=0,br2=0;
    string s1;

    for (;;)
    {
        s1=s.substr (0,br);
        s=s.substr (br,s.size()-1);

        for (i=1;i<=s1.size();i++)
        {
            ch=ch*10+(s1[i-1]-'0');
        }

        if (ch<del)
        {
            ch=ch*10+s[0]-'0';
            s=s.substr(1,s.size()-1);
        }

        ch=ch%del;
        test=ch;
        test1=del;

        while (test1>0)
        {
            test1=test1/10;
            br2++;
        }

        while (ch>0)
        {
            s=char(ch%10+'0')+s;
            ch=ch/10;
            br1++;
        }
        if (s[0]=='0' && br2<=s.size()) s='1'+s;
        if (br2==s.size())
        {
            for (i=0;i<s.size();i++)
            {
                ch1=ch1*0+s[i];
            }
            if (del>test) return test;
        }
        else if (br2>s.size()) break;
        br1=0;
        br2=0;
    }
    return test;
}

int main()
{
    cin>>n>>del;

    t=del;
    while (t>0)
    {
        br++;
        t=t/10;
    }

    s="1";
    for (i=1;i<=n-1;i++) s=s+'0';

    ost=delene (s,del);
    if (ost!=0) t=del-ost;
    else {t=1;ost=del;}
    br=0;

    while (t>0)
    {
        br++;
        t=t/10;
    }

    cout<<"1";
    for (i=2;i<=n-br;i++) cout<<"0";
    cout<<del-ost;
}
