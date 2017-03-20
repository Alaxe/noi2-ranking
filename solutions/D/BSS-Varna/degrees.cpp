#include<bits/stdc++.h>
using namespace std;
string step2(string n)
{
    string s;
    int i,c,pren=0;
    s.resize(n.size()+1,' ');
    for(i=n.size()-1;i>=0;i--)
    {
        c=((n[i]-'0')*2)%10+pren;
        pren=0;
        pren=((n[i]-'0')*2)/10;
        s[i+1]=c+'0';
    }
    if(pren)s[0]=pren+'0';
    if(!isdigit(s[0]))s.erase(s.begin(),s.begin()+1);
    return s;
}
int main()
{
    string t,a="1";
    int i;
    cin>>t;
    for(i=1;;i++)
    {
        a=step2(a);
        t.erase(t.begin(),t.begin()+a.size());
        if(t==""){cout<<i<<endl;return 0;}
    }
}
/**
2481632

248163264128256512102420484096819216384
*/
