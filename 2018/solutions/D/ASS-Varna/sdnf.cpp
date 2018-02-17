#include<bits/stdc++.h>
using namespace std;
int mas[100][100];
string sumLL(string a, string b)
{
    string rez;
    int pren=0,i,tmp;
    while (a.size()<b.size()) a="0"+a;
    while (b.size()<a.size()) b="0"+b;
    for (i=a.size()-1;i>=0;i--)
    {
        tmp=int(a[i]-'0')+int(b[i]-'0')+pren;
        pren=tmp/10;
        rez=char(tmp%10+'0')+rez;
    }
    if (pren)
    rez=char(pren+'0')+rez;
    return rez;
}
int main()
{
    string t="1",rez;
    long long n,i,j,sum=0;
    cin>>n;
    for (i=2;i<=n;i++)
    {
        rez="0";
        for (j=0;j<i;j++) rez=sumLL(rez,t);
        t=rez;
    }
    for (i=0;i<t.size();i++) sum+=int(t[i]-'0');
    cout<<sum<<endl;
    return 0;
}
