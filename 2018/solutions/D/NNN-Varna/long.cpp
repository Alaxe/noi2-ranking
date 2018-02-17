#include <bits/stdc++.h>
using namespace std;
string addstr(string a, string b)
{
    string res;
    int tmp, prenos=0;
    while (a.size()<b.size()) a="0"+a;
    while (b.size()<a.size()) b="0"+b;
    for (long long i=a.size()-1; i>=0; i--)
    {
        tmp=(int)(a[i]-'0')+(int)(b[i]-'0')+prenos;
        prenos=tmp/10;
        res=(char)(tmp%10+'0')+res;
    }
    if (prenos) res=(char)(prenos+'0')+res;
    return res;
}
string remstr(string a, string b)
{
    string res;
    int tmp, prenos=0;
    while (a.size()<b.size()) a="0"+a;
    while (b.size()<a.size()) b="0"+b;
    for (long long i=a.size()-1; i>=0; i--)
    {
        tmp=(int)(a[i]-'0')-(int)(b[i]-'0')-prenos;
        if (tmp<0) prenos=1, tmp+=10;
        else prenos=0;
        res=(char)(tmp%10+'0')+res;
    }
    return res;
}
string lesnodel(string a, string b)
{
    string res;
    long long as=0, bs=0;
    for (long long i=0; i<a.size(); i++) as*=10, as+=(int)(a[i]-'0');
    for (long long i=0; i<b.size(); i++) bs*=10, bs+=(int)(b[i]-'0');
    as=as%bs;
    if (as==0) return "0";
    while (as!=0) res=(char)(as%10+'0')+res, as/=10;
    return res;
}
string fixb(string b, string p)
{
    while (b.size()<p.size()) b="0"+b;
    return b;
}
string ost2str(string a, string b)
{
    string p;
    p+=a[0];
    long long j=1, cnt=1;
    while (cnt<a.size())
    {
        while (fixb(p, b)<fixb(b, p) && p=="0")
        {
            p+=a[j];
            while (p.size()>1 && p[0]=='0') p.erase(p.begin());
            j++;
            cnt++;
        }
        p=lesnodel(p, b);
        p+=a[j];
        j++;
        cnt++;
    }
    p=lesnodel(p, b);
    return p;
}
int main()
{
    string a="1", k, m;
    long long n;
    cin >> n >> k;
    while (a.size()<n) a+="0";
    m=ost2str(a, k);
    if (m=="0") cout << a << endl;
    else cout << addstr(a, remstr(k, m)) << endl;
}
